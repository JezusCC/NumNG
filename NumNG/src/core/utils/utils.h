#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* ���߻����ṩ��toString���������й��������Ҫʵ�ָ��Ե�toString����
		*/
		virtual ngString toString() = 0;
	};

	/*
	* Hash
	* ���ݹ�ϣ�㷨����һ����ϣ����
	* �����ȷ�����������������ͬ�Ľ��
	*/
	class Hash :public UtilBase {
	public:
		Hash() = delete;
		Hash(const Hash&) = delete;
		Hash(ngInt value);
		Hash(ngString value);
		virtual ~Hash() = default;

		ngBool operator==(const Hash& value)const;
		ngBool operator!=(const Hash& value)const;
		/*
		* ��ȡ��ϣ����
		*/
		ngInt getCode()const;

		ngString toString()override;
	private:
		ngInt m_code;
	};
	/*
	* UUID
	* ����һ��UUID����IDΨһ�Ҳ��ɸ���
	*/
	class UUID :public UtilBase {
	public:
		UUID();
		UUID(const UUID&) = delete;
		UUID(const UUID&&) = delete;
		virtual ~UUID() = default;

		void operator=(const UUID&) = delete;
		void operator=(const UUID&&) = delete;

		ngBool operator==(const UUID& value)const;
		ngBool operator!=(const UUID& value)const;

		/*
		* ����UUID���ַ���
		*/
		ngString getUUID()const;

		ngString toString()override;
	private:
		ngString m_id;
	};

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
		Timer(int32 time,ngBool repeat = false);
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

	/**
	 * ����һ��FPS����������Ҫÿ֡ѭ������
	 * FPS������ʹ��ʱ�Ӽ�������ÿ�����һ��FPS
	 */
	class FPSCounter :public UtilBase{
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

	class Color :public UtilBase {
	public:
		Color(float32 r, float32 g, float32 b, float32 a);
		Color(const Color& color);
		
		~Color();

		void setColor(float32 r, float32 g, float32 b, float32 a);
		void setColor(const Color& color);

		float32 getR()const;
		float32 getG()const;
		float32 getB()const;
		float32 getA()const;

		ngBool operator==(const Color& color)const;
		ngBool operator!=(const Color& color)const;

		ngString toString()override;
	private:
		float32 m_r;
		float32 m_g;
		float32 m_b;
		float32 m_a;
	};

	/**
	 * ������ָ��ת��������ָ��
	 * ��ת���ɹ����ظ�ָ�룬���򷵻ؿ�
	 */
	template<typename TargetType, typename SourceType>
	TargetType* Cast(SourceType* source) {
		return dynamic_cast<TargetType*>(source);
	}
	/**
	 * ��Դָ��ת����Ŀ��ָ��
	 * ��ת���ɹ����ظ�ָ�룬���򷵻ؿ�
	 */
	template<typename TargetType, typename SourceType>
	TargetType* ForceCast(SourceType* source) {
		return static_cast<TargetType*>(source);
	}
}