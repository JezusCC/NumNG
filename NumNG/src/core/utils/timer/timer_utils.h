#pragma once
#include "./timeline.h"

namespace ngUtils {
	/**
	 * 创建一个自带Timeline的定时器,精度为毫秒
	 * 该定时器需要每个Frame进行更新，当timeline运行时间超过了设定好的时间
	 * 该定时器停止
	 * 定时器创建时处在就绪状态，通过start函数进行启动
	 */
	class Timer {
	public:
		/**
		 * 定时器状态分为就绪、运行、停止三种
		 */
		enum class State {
			Standby,
			Running,
			Stop
		};
	public:
		/**
		 * @param time milliseconds for timer
		 * @param repeat when time over,timer will restart
		 */
		Timer(int32 time, ngBool repeat = false);
		Timer(const Timer& timer);

		//启动定时器
		void start();
		//停止计时器
		void stop();
		//重置定时器
		void reset();

		//该函数必须每帧被调用
		void update();
		//
		uint32 getTime()const;
		//
		Timer::State getState()const;
	private:
		//重复运行标识，与一次性标识互斥,定时器仅处在一次性运行或重复运行两种状态
		ngBool m_repeat;
		//运行状态
		State m_state;
		//设定好的时间,毫秒数
		uint32 m_time;
		//运行时tick计数
		ngInt m_tick_count;
		//最后一次更新tick
		ngInt m_last_up_tick;
		//
		Timeline m_timeline;
	};
}