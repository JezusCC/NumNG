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
		return env;
	}

	void destroyNgEnviroment(ngEnviroment* env)
	{
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		delete env;
	}

}