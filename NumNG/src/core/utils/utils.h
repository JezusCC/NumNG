#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* 工具基类提供的toString方法，所有工具类均需要实现各自的toString方法
		*/
		virtual ngString toString() = 0;
	};

	/*
	* Hash
	* 根据哈希算法产生一个哈希编码
	* 这个类确保在任意机器产生相同的结果
	*/
	class Hash :public UtilBase {
	public:
		Hash() = delete;
		Hash(const Hash&) = delete;
		Hash(ngInt value);
		Hash(ngString value);
		virtual ~Hash() = default;

		ngBool operator==(const Hash& value)const;
		ngBool operator!=(const Hash& value)const;
		/*
		* 获取哈希编码
		*/
		ngInt getCode()const;

		ngString toString()override;
	private:
		ngInt m_code;
	};
	/*
	* UUID
	* 产生一个UUID，该ID唯一且不可更改
	*/
	class UUID :public UtilBase {
	public:
		UUID();
		UUID(const UUID&) = delete;
		UUID(const UUID&&) = delete;
		virtual ~UUID() = default;

		void operator=(const UUID&) = delete;
		void operator=(const UUID&&) = delete;

		ngBool operator==(const UUID& value)const;
		ngBool operator!=(const UUID& value)const;

		/*
		* 返回UUID的字符串
		*/
		ngString getUUID()const;

		ngString toString()override;
	private:
		ngString m_id;
	};

	/**
	 * 创建一个时间轴对象，该时间轴记录自对象产生以来经过的tick数
	 * 该tick长度取决于精度，目前提供的精度有
	 * 秒
	 * 毫秒
	 * 微秒
	 * 三种级别,默认精度为毫秒
	 */
	class Timeline {
	public:
		enum class Precision {
			Second,
			Milli,
			Micro
		};
	public:
		//创建一个精度为percision的时间轴
		Timeline(Precision precision = Precision::Milli);

		//获取自启动时运行的tick
		ngInt getTick()const;

		ngFloat getSeconds()const;

		Timeline::Precision getPrecision()const;

	private:
		//初始tick
		ngInt m_init_tick;
		//运行tick
		ngInt m_tick;
		//运行精度
		Precision m_precision;

		std::chrono::time_point<std::chrono::steady_clock> m_time_point;
	};

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
		Timer(int32 time,ngBool repeat = false);
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

	/**
	 * 创建一个FPS计数器，需要每帧循环调用
	 * FPS计数器使用时钟计数法，每秒更新一次FPS
	 */
	class FPSCounter :public UtilBase{
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