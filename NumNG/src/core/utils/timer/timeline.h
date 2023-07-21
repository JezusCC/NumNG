#pragma once
#include "../common/common.h"

namespace ngUtils {
	/**
	 * ����һ��ʱ������󣬸�ʱ�����¼�Զ����������������tick��
	 * ��tick����ȡ���ھ��ȣ�Ŀǰ�ṩ�ľ�����
	 * ��
	 * ����
	 * ΢��
	 * ���ּ���,Ĭ�Ͼ���Ϊ����
	 */
	class Timeline {
	public:
		enum class Precision {
			Second,
			Milli,
			Micro
		};
	public:
		//����һ������Ϊpercision��ʱ����
		Timeline(Precision precision = Precision::Milli);

		//��ȡ������ʱ���е�tick
		ngInt getTick()const;

		ngFloat getSeconds()const;

		Timeline::Precision getPrecision()const;

	private:
		//��ʼtick
		ngInt m_init_tick;
		//����tick
		ngInt m_tick;
		//���о���
		Precision m_precision;

		std::chrono::time_point<std::chrono::steady_clock> m_time_point;
	};
}