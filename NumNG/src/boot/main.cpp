#include "../core/utils/utils.h"
#include "../core/entry/entrys.h"

int main(int argc, char* argv[]) {

	auto env = ngCore::createNgEnviroment(argc, argv);

	ngCore::Window2D window("Hello", 1366, 768);

	while (!window.shouldClose())
	{
		window.clearBuffer();

		window.procEvent();
	}

	ngCore::destroyNgEnviroment(env);

	return 0;
}