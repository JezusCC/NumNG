#pragma once
#include <string>

/*
* @description
* xtype.h
* 该头文件定义了NumNG使用的数据类型
* 为了维持各模块之间的数据类型通用，所有文件应尽量使用该头文件中定义的变量进行声明
* @author cytus
* @date 2023年6月8日21点34分
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
* 整数类型，尽量使用该类型来进行变量声明
*/
using ngInt = int64;
/**
* ngUint
* 无符号整数类型，整数类型的无符号版本
*/
using ngUInt = uint64;
/**
* ngFloat
* 浮点数类型，尽量使用该类型来进行变量声明
*/
using ngFloat = float64;
/**
* ngChar
* 字符类型，尽量使用该类型来进行变量声明
*/
using ngChar = char8;
/**
* ngUChar
* 无符号字符类型，字符类型的无符号版本
*/
using ngUChar = uchar8;
/**
* ngByte
* 字节类型，表示一个字节的数据
*/
using ngByte = uchar8;
/**
* ngBool
* 布尔类型，尽量使用该类型来进行变量声明
*/
using ngBool = bool;
/**
* ngString
* 字符串类型，尽量使用该类型来进行变量声明
*/
using ngString = string;
/**
* ngCNString
* 宽字符串类型，字符串的宽字符版本，可容纳中文
*/
using ngCNString = wstring;