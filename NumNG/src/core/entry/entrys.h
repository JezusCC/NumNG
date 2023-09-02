#pragma once
#include "../application/window2d.h"

namespace ngCore {

	/**
	 * ngEnviroment
	 * ng 运行环境，包含引擎启动的核心参数及其内容
	 */
	struct ngEnviroment {
		//环境初始化标识
		ngBool env_init;
		ngBool graphic_lib_init;
		ngBool texture_lib_init;
		ngBool font_lib_init;
		ngBool audio_lib_init;
		//程序运行参数个数
		int32 arg_nums;
		//程序运行参数值指针
		ngChar** arg_array;
	};

	/**
	 * 创建一个唯一的运行环境，当环境不需要时必须调用相应的销毁函数以便清除掉运行环境
	 */
	ngEnviroment* createNgEnviroment(int argc,char** argv);
	/**
	 * 销毁运行环境
	 */
	void destroyNgEnviroment(ngEnviroment* env);
}