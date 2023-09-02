#pragma once

#include "../timer/timer_utils.h"

namespace ngUtils {
	/**
	 * 创建一个FPS计数器，需要每帧循环调用
	 * FPS计数器使用时钟计数法，每秒更新一次FPS
	 */
	class FPSCounter :public UtilBase {
	public:
		FPSCounter();
		FPSCounter(const FPSCounter&) = delete;
		FPSCounter(const FPSCounter&&) = delete;
		void operator=(const FPSCounter&) = delete;
		void operator=(const FPSCounter&&) = delete;

		~FPSCounter();

		//该函数必须每帧被调用
		void update();
		//
		int32 getFps()const;

		ngString toString();
	private:
		//创建一个一秒的重复定时器
		Timer* m_timer;
		//
		int32 m_fps_count;
		//每秒计算一次
		int32 m_fps;
	};
}