#include "./fps_utils.h"

namespace ngUtils {
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
		if (m_timer->getState() == Timer::State::Stop) {
			m_fps = m_fps_count;
			m_fps_count = 0;
		}
		m_timer->update();
	}

	int32 FPSCounter::getFps() const
	{
		return m_fps;
	}

	ngString FPSCounter::toString()
	{
		std::stringstream ss;
		ss << "FPS:" << m_fps;
		return ss.str();
	}
}