#include "window2d.h"
#include "SDL2/SDL.h"
namespace ngCore {
	Window2D::Window2D(const ngString& title, uint32 width, uint32 height) :Application(title, width, height)
	{
		if (!create()) {
			m_window = nullptr;
			m_renderer = nullptr;
		}
	}

	Window2D::~Window2D()
	{
		if (m_renderer) {
			SDL_DestroyRenderer(m_renderer);
		}
		if (m_window) {
			SDL_DestroyWindow(m_window);
		}
	}

	SDL_Window* Window2D::getWindowInstance() const
	{
		return m_window;
	}

	SDL_Renderer* Window2D::getRendererInstance() const
	{
		return m_renderer;
	}

	void Window2D::setTitle(const ngString& title)
	{
		SDL_SetWindowTitle(m_window, title.c_str());
		Application::setTitle(title);
	}

	void Window2D::setPosition(uint32 pos_x, uint32 pos_y)
	{
		SDL_SetWindowPosition(m_window, pos_x, pos_y);
		Application::setPosition(pos_x, pos_y);
	}

	void Window2D::setPositionX(uint32 pos_x)
	{
		SDL_SetWindowPosition(m_window, pos_x, m_position_y);
		Application::setPositionX(pos_x);
	}

	void Window2D::setPositionY(uint32 pos_y)
	{
		SDL_SetWindowPosition(m_window, m_position_x, pos_y);
		Application::setPositionX(pos_y);
	}

	void Window2D::setSize(uint32 width, uint32 height)
	{
		SDL_SetWindowSize(m_window, width, height);
		Application::setSize(width, height);
	}

	void Window2D::setWidth(uint32 width)
	{
		SDL_SetWindowSize(m_window, width,m_height);
		Application::setWidth(width);
	}

	void Window2D::setHeight(uint32 height)
	{
		SDL_SetWindowSize(m_window, m_width, height);
		Application::setHeight(height);
	}

	void Window2D::procEvent()
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev) != 0) {
			switch (ev.type)
			{
			case SDL_EventType::SDL_QUIT:
				m_loop = false;
				break;
			//键盘事件
			case SDL_EventType::SDL_KEYDOWN:
			case SDL_EventType::SDL_KEYUP:

				break;
			//鼠标事件
			case SDL_EventType::SDL_MOUSEBUTTONDOWN:
			case SDL_EventType::SDL_MOUSEBUTTONUP:
			case SDL_EventType::SDL_MOUSEMOTION:
			case SDL_EventType::SDL_MOUSEWHEEL:

				break;
			default:
				break;
			}
		}
	}

	void Window2D::clearBuffer()
	{
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(m_renderer);
		SDL_RenderPresent(m_renderer);
	}

	ngBool Window2D::shouldClose()
	{
		return !m_loop;
	}

	bool Window2D::create()
	{
		int32 win_flag = 0;
		win_flag |= SDL_WindowFlags::SDL_WINDOW_SHOWN | SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI;
		if (m_fullscreen) {
			win_flag |= SDL_WindowFlags::SDL_WINDOW_FULLSCREEN;
		}
		int32 ret = SDL_CreateWindowAndRenderer(m_width, m_height, win_flag, &m_window, &m_renderer);
		if (ret != 0) {
			m_window = nullptr;
			m_renderer = nullptr;
			return false;
		}
		SDL_SetWindowTitle(m_window, m_title.c_str());
		return true;
	}
}