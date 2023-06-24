#include "utils.h"

namespace ngUtil {
	Hash::Hash(ngInt value)
	{
		std::stringstream ss;
		ss << value;
		std::hash<ngString> hasher;
		this->m_code = hasher(ss.str());
	}

	Hash::Hash(ngString value)
	{
		std::hash<ngString> hasher;
		this->m_code = hasher(value);
	}
	ngBool Hash::operator==(const Hash& value) const
	{
		return this->m_code == value.m_code;
	}
	ngBool Hash::operator!=(const Hash& value) const
	{
		return this->m_code != value.m_code;
	}
	ngInt Hash::getCode() const
	{
		return m_code;
	}
	ngString Hash::toString()
	{
		std::stringstream ss;
		ss << m_code;
		ngString ret = ss.str();
		return ret;
	}
	UUID::UUID()
	{
		std::random_device rd;
		std::uniform_int_distribution<uint64_t> dist(0ULL, 0xFFFFFFFFFFFFFFFFULL);
		uint64_t ab = dist(rd);
		uint64_t cd = dist(rd);
		uint32_t a, b, c, d;
		std::stringstream ss;
		ab = (ab & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;
		cd = (cd & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;
		a = (ab >> 32U);
		b = (ab & 0xFFFFFFFFU);
		c = (cd >> 32U);
		d = (cd & 0xFFFFFFFFU);
		ss << std::hex << std::nouppercase << std::setfill('0');
		ss << std::setw(8) << (a) << '-';
		ss << std::setw(4) << (b >> 16U) << '-';
		ss << std::setw(4) << (b & 0xFFFFU) << '-';
		ss << std::setw(4) << (c >> 16U) << '-';
		ss << std::setw(4) << (c & 0xFFFFU);
		ss << std::setw(8) << d;
		
		this->m_id = ss.str();
	}
	ngBool UUID::operator==(const UUID& value) const
	{
		return this->m_id == value.m_id;
	}
	ngBool UUID::operator!=(const UUID& value) const
	{
		return this->m_id != value.m_id;
	}
	ngString UUID::getUUID() const
	{
		return this->m_id;
	}
	ngString UUID::toString()
	{
		return this->m_id;
	}
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
		case ngUtil::Timeline::Precision::Second:
			return std::chrono::duration_cast<std::chrono::seconds>(t_time - m_time_point).count();
			break;
		case ngUtil::Timeline::Precision::Milli:
			return std::chrono::duration_cast<std::chrono::milliseconds>(t_time - m_time_point).count();
			break;
		case ngUtil::Timeline::Precision::Micro:
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

	Timer::Timer(int32 time, ngBool repeat):m_timeline(Timeline(Timeline::Precision::Milli))
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
		case ngUtil::Timer::State::Standby:
			m_last_up_tick = m_timeline.getTick();
			break;
		case ngUtil::Timer::State::Running:
			m_tick_count += m_timeline.getTick() - m_last_up_tick;
			m_last_up_tick = m_timeline.getTick();
			if (m_tick_count >= m_time) {
				m_state = State::Stop;
			}
			break;
		case ngUtil::Timer::State::Stop:
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

	ngUtil::Timer::State Timer::getState() const
	{
		return m_state;
	}

	FPSCounter::FPSCounter()
	{
		m_fps = 0;
		m_fps_count = 0;
		m_timer = new Timer(1000, true);
		m_timer->start();
	}

	FPSCounter::~FPSCounter()
	{
		delete m_timer;
	}

	void FPSCounter::update()
	{
		m_fps_count++;
		if (m_timer->getState()==Timer::State::Stop) {
			m_fps = m_fps_count;
			m_fps_count = 0;
		}
		m_timer->update();
	}

	int32 FPSCounter::getFps() const
	{
		return m_fps;
	}

}
