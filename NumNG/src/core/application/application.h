#pragma once
#include "../../preclude/preclude.h"

namespace ngCore {
	/**
	 * 创建一个应用程序，该应用程序具有基本的属性
	 */
	class Application {
	public:
		Application(const ngString& title, uint32 width, uint32 height);
		virtual ~Application() = default;

		/**
		 * 设置窗口标题
		 * @param title 标题
		 */
		void setTitle(const ngString& title);
		/**
		 * 设置窗口宽
		 * @param width 宽
		 */
		void setWidth(uint32 width);
		/**
		 * 设置窗口高
		 * @param height 高
		 */
		void setHeight(uint32 height);
		/**
		 * 设置窗口尺寸
		 * @param width 宽
		 * @param height 高
		 */
		void setSize(uint32 width, uint32 height);
		/**
		 * 设置窗口位置
		 * @param pos_x X 坐标
		 */
		void setPositionX(uint32 pos_x);
		/**
		 *设置窗口位置
		 * @param pos_y Y 坐标
		 */
		void setPositionY(uint32 pos_y);
		/**
		 * 设置窗口位置
		 * @param pos_x X 坐标
		 * @param pos_y Y 坐标
		 */
		void setPosition(uint32 pos_x, uint32 pos_y);
		/**
		 *获取窗口标题
		 */
		ngString getTitle()const;
		/**
		 * 获取窗口宽
		 */
		uint32 getWidth()const;
		/**
		 * 获取窗口高
		 */
		uint32 getHeight()const;
		/**
		 * 获取窗口X坐标
		 */
		uint32 getPositionX()const;
		/**
		 * 获取窗口Y坐标
		 */
		uint32 getPositionY()const;

		virtual void procEvent() = 0;
		virtual void clearBuffer() = 0;
		virtual ngBool shouldClose() = 0;

	protected:
		ngBool m_loop;
		uint32 m_width;
		uint32 m_height;
		uint32 m_position_x;
		uint32 m_position_y;
		ngString m_title;
	};
}