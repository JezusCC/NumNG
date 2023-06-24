#pragma once
#include "../preclude/preclude.h"
#include "../application/window2d.h"

namespace ngCore {

	/**
	 * ngEnviroment
	 * ng ���л������������������ĺ��Ĳ�����������
	 */
	struct ngEnviroment {
		//������ʼ����ʶ
		ngBool env_init;
		//�������в�������
		int32 arg_nums;
		//�������в���ֵָ��
		ngChar** arg_array;
		//����
		Window2D* window;
	};

	/**
	 * ����һ��Ψһ�����л���������������Ҫʱ���������Ӧ�����ٺ����Ա���������л���
	 */
	ngEnviroment* createNgEnviroment(int argc,char** argv);
	/**
	 * �������л���
	 */
	void destroyNgEnviroment(ngEnviroment* env);
}