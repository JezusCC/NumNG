#include "application.h"

namespace ngCore {
	Application::Application(const ngString& title, uint32 width, uint32 height)
	{
		m_loop = true;
		m_title = title;
		m_width = width;
		m_height = height;
		m_position_x = 0;
		m_position_y = 0;
	}

	void Application::setTitle(const ngString& title)
	{
		m_title = title;
	}

	void Application::setWidth(uint32 width)
	{
		m_width = width;
	}

	void Application::setHeight(uint32 height)
	{
		m_height = height;
	}

	void Application::setSize(uint32 width, uint32 height)
	{
		m_width = width;
		m_height = height;
	}

	void Application::setPositionX(uint32 pos_x)
	{
		m_position_x = pos_x;
	}

	void Application::setPositionY(uint32 pos_y)
	{
		m_position_y = pos_y;
	}

	void Application::setPosition(uint32 pos_x, uint32 pos_y)
	{
		m_position_x = pos_x;
		m_position_y = pos_y;
	}

	ngString Application::getTitle() const
	{
		return m_title;
	}

	uint32 Application::getWidth() const
	{
		return m_width;
	}

	uint32 Application::getHeight() const
	{
		return m_height;
	}

	uint32 Application::getPositionX() const
	{
		return m_position_x;
	}

	uint32 Application::getPositionY() const
	{
		return m_position_y;
	}
}