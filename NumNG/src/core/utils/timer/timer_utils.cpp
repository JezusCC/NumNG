#include "./timer_utils.h"

namespace ngUtils {
	Timer::Timer(int32 time, ngBool repeat) :m_timeline(Timeline(Timeline::Precision::Milli))
	{
		m_time = time;
		m_repeat = repeat;
		m_state = State::Standby;
		m_tick_count = 0;
		m_last_up_tick = 0;
	}

	Timer::Timer(const Timer& timer) :m_timeline(Timeline(Timeline::Precision::Milli))
	{
		m_time = timer.m_time;
		m_repeat = timer.m_repeat;
		m_state = timer.m_state;
		m_tick_count = timer.m_tick_count;
		m_last_up_tick = timer.m_last_up_tick;
	}

	void Timer::start()
	{
		m_state = State::Running;
	}

	void Timer::stop()
	{
		m_state = State::Stop;
	}

	void Timer::reset()
	{
		m_tick_count = 0;
		m_state = State::Standby;
	}

	void Timer::update()
	{
		switch (m_state)
		{
		case ngUtils::Timer::State::Standby:
			m_last_up_tick = m_timeline.getTick();
			break;
		case ngUtils::Timer::State::Running:
			m_tick_count += m_timeline.getTick() - m_last_up_tick;
			m_last_up_tick = m_timeline.getTick();
			if (m_tick_count >= m_time) {
				m_state = State::Stop;
			}
			break;
		case ngUtils::Timer::State::Stop:
			if (m_repeat) {
				reset();
				start();
			}
			break;
		default:
			break;
		}
	}

	uint32 Timer::getTime() const
	{
		return m_tick_count;
	}

	ngUtils::Timer::State Timer::getState() const
	{
		return m_state;
	}
}