#include "entrys.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
namespace ngCore {

	ngEnviroment* createNgEnviroment(int argc,char** argv)
	{	
		ngEnviroment* env = new ngEnviroment;
		::memset(env, 0, sizeof(ngEnviroment));
		env->env_init = false;
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			env->graphic_lib_init = false;
		}
		env->graphic_lib_init = true;
		int img_flag = IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG | IMG_InitFlags::IMG_INIT_TIF | IMG_InitFlags::IMG_INIT_WEBP;
		if (IMG_Init(img_flag) == 0) {
			env->texture_lib_init = false;
		}
		env->texture_lib_init = true;
		if (TTF_Init() != 0) {
			env->font_lib_init = false;
		}
		env->font_lib_init = true;
		int mix_flag = MIX_InitFlags::MIX_INIT_FLAC | MIX_InitFlags::MIX_INIT_MP3 
			| MIX_InitFlags::MIX_INIT_MID |MIX_InitFlags::MIX_INIT_OGG | MIX_InitFlags::MIX_INIT_MOD | MIX_InitFlags::MIX_INIT_OPUS;
		if (Mix_Init(mix_flag) == 0) {
			env->audio_lib_init = false;
		}
		env->audio_lib_init = true;
		env->arg_nums = argc;
		env->arg_array = argv;
		env->env_init = true;

		//初始化各种绑定函数
		env->beforeRunFunc = [](ngEnviroment* env) {};
		env->afterRunFunc = [](ngEnviroment* env) {};
		env->updateFunc = [](ngEnviroment* env) {};

		return env;
	}

	void destroyNgEnviroment(ngEnviroment* env)
	{
		if(env->window != nullptr){
			delete env->window;
		}

		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		delete env;
	}

    void createRuntimeWindow(ngEnviroment *env, const ngString &title, int32 width, int32 height)
    {
		if(env != nullptr && env->env_init){
			if(env->window == nullptr){
				env->window = new Window2D(title,width,height);
			}else{
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Window is already created");
			}
		}else{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Environment is not initialized");
		}
    }
    void runNgApplication(ngEnviroment *env, ngStd::function<void(ngEnviroment *env)> updateFunc)
    {
		if(env != nullptr && env->env_init){
			env->updateFunc = updateFunc;
			env->beforeRunFunc(env);
			if(env->window != nullptr){
			while(env->window->shouldClose() == false){
				env->window->procEvent();
				env->updateFunc(env);
				env->window->clearBuffer();
			}
			env->afterRunFunc(env);
			}else{
				SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Window is not created");
			}
		}else{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Environment is not initialized");
		}
    }
    void bindBeforeRunFunc(ngEnviroment *env, ngStd::function<void(ngEnviroment *env)> func)
    {
		if(env != nullptr && env->env_init){
			env->beforeRunFunc = func;
		}else{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Environment is not initialized");
		}
    }
    void bindAfterRunFunc(ngEnviroment *env, ngStd::function<void(ngEnviroment *env)> func)
    {
		if(env != nullptr && env->env_init){
			env->afterRunFunc = func;
		}else{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Environment is not initialized");
		}
    }
    void bindUpdateFunc(ngEnviroment *env, ngStd::function<void(ngEnviroment *env)> func)
    {
		if(env != nullptr && env->env_init){
			env->updateFunc = func;
		}else{
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Environment is not initialized");
		}
    }
}