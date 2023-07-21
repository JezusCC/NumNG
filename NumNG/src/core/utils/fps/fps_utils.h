#pragma once

#include "../timer/timer_utils.h"

namespace ngUtils {
	/**
	 * ����һ��FPS����������Ҫÿ֡ѭ������
	 * FPS������ʹ��ʱ�Ӽ�������ÿ�����һ��FPS
	 */
	class FPSCounter :public UtilBase {
	public:
		FPSCounter();
		FPSCounter(const FPSCounter&) = delete;
		FPSCounter(const FPSCounter&&) = delete;
		void operator=(const FPSCounter&) = delete;
		void operator=(const FPSCounter&&) = delete;

		~FPSCounter();

		//�ú�������ÿ֡������
		void update();
		//
		int32 getFps()const;

		ngString toString();
	private:
		//����һ��һ����ظ���ʱ��
		Timer* m_timer;
		//
		int32 m_fps_count;
		//ÿ�����һ��
		int32 m_fps;
	};
}