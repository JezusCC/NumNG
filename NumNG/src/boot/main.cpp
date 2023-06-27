#include "../core/utils/utils.h"
#include "../core/entry/entrys.h"
#include "SDL2/SDL.h"
#include "imgui4sdl2raw/imgui.h"
#include "imgui4sdl2raw/imgui_impl_sdl.h"
#include "imgui4sdl2raw/imgui_impl_sdlrenderer.h"

#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

int main(int argc, char* argv[]) {

	auto env = ngCore::createNgEnviroment(argc, argv);

	ngCore::destroyNgEnviroment(env);

	return 0;
}