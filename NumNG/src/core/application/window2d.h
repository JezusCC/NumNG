#pragma once
#include "application.h"

struct SDL_Window;
struct SDL_Renderer;
struct ImGuiContext;
struct ImGuiIO;

namespace ngCore {

	/**
	 * ����һ������2D��Ⱦ���Ĵ��ڣ��ô��ھ�����������ĺ�SDL��Ⱦ��
	 */
	class Window2D :public Application {
	public:
		Window2D(const ngString& title, uint32 width, uint32 height);
		~Window2D();

		SDL_Window* getWindowInstance()const;
		SDL_Renderer* getRendererInstance()const;
		ImGuiContext* getGuiContext()const;
		ImGuiIO getGuiOption()const;

		/**
		 * ��ȡFPS
		 */
		ngFloat getFramerate()const;
		/**
		 * ���ô��ڱ���
		 */
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
		 * ��������
		 */
		bool create();

	private:
		ngBool m_fullscreen;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		//imgui context
		ImGuiContext* m_gui_context;
	};
}