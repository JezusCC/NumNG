#pragma once

namespace ngUtils {
//	/*
//	* ����ͨ�õ��¼�����
//	*/
//	template<typename T>
//	struct EventDataType {};
//
//#define EV_SPECIALIZATION_EVENT_DATA(_struct,_name)\
//	template<>\
//	struct ngUtils::EventDataType<_struct> {\
//			_struct _name;\
//	}
//	/**
//	 * �����¼��������ͣ������ͱ�����һ���ṹ�壬�¼��ַ���ת���¼�ʱͨ��name��ȡ��ת��������
//	 */
//#define EV_CUSTOM_EVENT_DATA_DEFINE(_struct,_name) EV_SPECIALIZATION_EVENT_DATA(_struct,_name)
//#define EV_GET_CUSTOM_EVENT_DATA_TYPE(_struct) ngUtils::EventDataType<_struct>

	//�յ��¼�����
	//�û�������չ���Զ����EventData�����ǽ����¼�����Ҫ����ת��
	class EventData {
	public:
		EventData() = default;
		virtual ~EventData() = default;
	};

}