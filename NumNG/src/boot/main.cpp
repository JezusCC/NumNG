#include "../core/utils/utils.h"

int main(int argc, char* argv[]) {

	std::cout << ngUtil::Hash("123").toString() << std::endl;
	std::cout << ngUtil::Hash("123").toString() << std::endl;
	std::cout << ngUtil::UUID().toString() << std::endl;
	std::cout << ngUtil::UUID().toString() << std::endl;
	std::cout << ngUtil::UUID().toString() << std::endl;
	std::cout << ngUtil::UUID().toString() << std::endl;

	return 0;
}