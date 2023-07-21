#pragma once
#include "./timeline.h"

namespace ngUtils {
	/**
	 * ����һ���Դ�Timeline�Ķ�ʱ��,����Ϊ����
	 * �ö�ʱ����Ҫÿ��Frame���и��£���timeline����ʱ�䳬�����趨�õ�ʱ��
	 * �ö�ʱ��ֹͣ
	 * ��ʱ������ʱ���ھ���״̬��ͨ��start������������
	 */
	class Timer {
	public:
		/**
		 * ��ʱ��״̬��Ϊ���������С�ֹͣ����
		 */
		enum class State {
			Standby,
			Running,
			Stop
		};
	public:
		/**
		 * @param time milliseconds for timer
		 * @param repeat when time over,timer will restart
		 */
		Timer(int32 time, ngBool repeat = false);
		Timer(const Timer& timer);

		//������ʱ��
		void start();
		//ֹͣ��ʱ��
		void stop();
		//���ö�ʱ��
		void reset();

		//�ú�������ÿ֡������
		void update();
		//
		uint32 getTime()const;
		//
		Timer::State getState()const;
	private:
		//�ظ����б�ʶ����һ���Ա�ʶ����,��ʱ��������һ�������л��ظ���������״̬
		ngBool m_repeat;
		//����״̬
		State m_state;
		//�趨�õ�ʱ��,������
		uint32 m_time;
		//����ʱtick����
		ngInt m_tick_count;
		//���һ�θ���tick
		ngInt m_last_up_tick;
		//
		Timeline m_timeline;
	};
}