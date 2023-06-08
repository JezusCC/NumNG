#pragma once
#include <string>

/*
* @description
* xtype.h
* ��ͷ�ļ�������NumNGʹ�õ���������
* Ϊ��ά�ָ�ģ��֮�����������ͨ�ã������ļ�Ӧ����ʹ�ø�ͷ�ļ��ж���ı�����������
* @author cytus
* @date 2023��6��8��21��34��
*/

using int32 = int32_t;
using int64 = int64_t;

using uint32 = uint32_t;
using uint64 = uint64_t;

using float32 = float;
using float64 = double;

using char8 = char;
using char16 = char16_t;

using uchar8 = unsigned char;
using uchar16 = char16_t;

using string = std::string;
using wstring = std::wstring;

/**
* ngInt
* �������ͣ�����ʹ�ø����������б�������
*/
using ngInt = int64;
/**
* ngUint
* �޷����������ͣ��������͵��޷��Ű汾
*/
using ngUInt = uint64;
/**
* ngFloat
* ���������ͣ�����ʹ�ø����������б�������
*/
using ngFloat = float64;
/**
* ngChar
* �ַ����ͣ�����ʹ�ø����������б�������
*/
using ngChar = char8;
/**
* ngUChar
* �޷����ַ����ͣ��ַ����͵��޷��Ű汾
*/
using ngUChar = uchar8;
/**
* ngByte
* �ֽ����ͣ���ʾһ���ֽڵ�����
*/
using ngByte = uchar8;
/**
* ngBool
* �������ͣ�����ʹ�ø����������б�������
*/
using ngBool = bool;
/**
* ngString
* �ַ������ͣ�����ʹ�ø����������б�������
*/
using ngString = string;
/**
* ngCNString
* ���ַ������ͣ��ַ����Ŀ��ַ��汾������������
*/
using ngCNString = wstring;