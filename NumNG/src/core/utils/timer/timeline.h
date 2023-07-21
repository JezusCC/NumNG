#pragma once
#include "../common/common.h"

namespace ngUtils {
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
}