#pragma once
#include "../preclude/preclude.h"

namespace ngCore {
	/**
	 * ����һ��Ӧ�ó��򣬸�Ӧ�ó�����л���������
	 */
	class Application {
	public:
		Application(const ngString& title, uint32 width, uint32 height);
		virtual ~Application() = default;

		/**
		 * ���ô��ڱ���
		 * @param title ����
		 */
		void setTitle(const ngString& title);
		/**
		 * ���ô��ڿ�
		 * @param width ��
		 */
		void setWidth(uint32 width);
		/**
		 * ���ô��ڸ�
		 * @param height ��
		 */
		void setHeight(uint32 height);
		/**
		 * ���ô��ڳߴ�
		 * @param width ��
		 * @param height ��
		 */
		void setSize(uint32 width, uint32 height);
		/**
		 * ���ô���λ��
		 * @param pos_x X ����
		 */
		void setPositionX(uint32 pos_x);
		/**
		 *���ô���λ��
		 * @param pos_y Y ����
		 */
		void setPositionY(uint32 pos_y);
		/**
		 * ���ô���λ��
		 * @param pos_x X ����
		 * @param pos_y Y ����
		 */
		void setPosition(uint32 pos_x, uint32 pos_y);
		/**
		 *��ȡ���ڱ���
		 */
		ngString getTitle()const;
		/**
		 * ��ȡ���ڿ�
		 */
		uint32 getWidth()const;
		/**
		 * ��ȡ���ڸ�
		 */
		uint32 getHeight()const;
		/**
		 * ��ȡ����X����
		 */
		uint32 getPositionX()const;
		/**
		 * ��ȡ����Y����
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