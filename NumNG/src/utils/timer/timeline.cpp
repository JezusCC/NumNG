#include "./timeline.h"

namespace ngUtils {
	Timeline::Timeline(Precision precision)
	{
		this->m_init_tick = 0;
		this->m_tick = 0;
		this->m_precision = precision;
		this->m_time_point = std::chrono::steady_clock::now();
	}

	ngInt Timeline::getTick() const
	{
		auto t_time = std::chrono::steady_clock::now();
		switch (m_precision)
		{
		case ngUtils::Timeline::Precision::Second:
			return std::chrono::duration_cast<std::chrono::seconds>(t_time - m_time_point).count();
			break;
		case ngUtils::Timeline::Precision::Milli:
			return std::chrono::duration_cast<std::chrono::milliseconds>(t_time - m_time_point).count();
			break;
		case ngUtils::Timeline::Precision::Micro:
			return std::chrono::duration_cast<std::chrono::microseconds>(t_time - m_time_point).count();
			break;
		default:
			break;
		}
		return -1;
	}

	ngFloat Timeline::getSeconds() const
	{
		auto t_time = std::chrono::steady_clock::now();
		std::chrono::duration<ngFloat> duration = std::chrono::duration_cast<std::chrono::seconds>(t_time - m_time_point);
		return duration.count();
	}

	Timeline::Precision Timeline::getPrecision() const
	{
		return this->m_precision;
	}
}