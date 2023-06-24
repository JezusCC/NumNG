#pragma once
#include "application.h"

struct SDL_Window;
struct SDL_Renderer;

namespace ngCore {
	/**
	 * 创建一个包含2D渲染器的窗口，该窗口具有相关上下文和SDL渲染器
	 */
	class Window2D :public Application {
	public:
		Window2D(const ngString& title, uint32 width, uint32 height);
		~Window2D();

		SDL_Window* getWindowInstance()const;
		SDL_Renderer* getRendererInstance()const;

		void setTitle(const ngString& title);
		void setPosition(uint32 pos_x, uint32 pos_y);
		void setPositionX(uint32 pos_x);
		void setPositionY(uint32 pos_y);
		void setSize(uint32 width, uint32 height);
		void setWidth(uint32 width);
		void setHeight(uint32 height);

		void procEvent();
		void clearBuffer();
		ngBool shouldClose();

	private:
		/**
		 * 创建窗口
		 */
		bool create();

	private:
		ngBool m_fullscreen;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};
}