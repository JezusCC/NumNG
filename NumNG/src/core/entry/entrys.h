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

		//运行时应用程序窗口
		Application* window;
		//运行时程序循环
		ngStd::function<void(ngEnviroment* env)> updateFunc;
		//运行时程序运行前钩子函数
		ngStd::function<void(ngEnviroment* env)> beforeRunFunc;
		//运行时程序运行后钩子函数
		ngStd::function<void(ngEnviroment* env)> afterRunFunc;
	};

	/**
	 * 创建一个唯一的运行环境，当环境不需要时必须调用相应的销毁函数以便清除掉运行环境
	 */
	ngEnviroment* createNgEnviroment(int argc,char** argv);
	/**
	 * 销毁运行环境
	 */
	void destroyNgEnviroment(ngEnviroment* env);
	/**
	 * @brief 创建运行时窗口,在调用此函数前确保已经调用了createNgEnviroment
	 * 
	 * @param env 
	 * @param title 
	 * @param width 
	 * @param height 
	 */
	void createRuntimeWindow(ngEnviroment* env, const ngString& title, int32 width, int32 height);
	/**
	 * @brief 运行ng应用程序,在调用此函数前确保已经调用了createRuntimeWindow
	 * 此函数还具有一系列的钩子函数，可以在此函数调用时控制程序运行前后的一些操作
	 * 如果你有一些需要在程序运行前后做的操作，可以通过绑定钩子函数来实现
	 * 
	 * @param env 
	 * @param updateFunc 此函数会在运行时被每帧调用
	 */
	void runNgApplication(ngEnviroment* env, ngStd::function<void(ngEnviroment* env)> updateFunc = [](ngEnviroment* env){});
	/**
	 * @brief 绑定运行时程序运行前钩子函数,此函数必须在调用runNgApplication之前调用，否则无效
	 * 
	 * @param env 
	 * @param func 
	 */
	void bindBeforeRunFunc(ngEnviroment* env, ngStd::function<void(ngEnviroment* env)> func);

	/**
	 * @brief 绑定运行时程序运行后钩子函数,此函数必须在调用runNgApplication之前调用，否则无效
	 * 
	 * @param env 
	 * @param func 
	 */
	void bindAfterRunFunc(ngEnviroment* env, ngStd::function<void(ngEnviroment* env)> func);

	/**
	 * @brief 绑定运行时程序每帧更新钩子函数,如果此前有绑定过此函数，那么此函数会覆盖之前的绑定
	 * 
	 * @param env 
	 * @param func 
	 */
	void bindUpdateFunc(ngEnviroment* env, ngStd::function<void(ngEnviroment* env)> func);
}