#pragma once

/**
 * 标准IO流库
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

/**
 * 标准时间库
*/
#include <chrono>
#include <ctime>

/**
 * 标准随机数库
*/
#include <random>
/**
 * 标准函数包装器库
*/
#include <functional>

/**
 * 其他标准库
*/
#include <limits>
#include <cstdint>
#include <type_traits>

/**
 * 标准容器库
*/
#include <map>
#include <vector>

/**
 * 标准算法库
*/
#include <algorithm>

/**
 * 标准文件系统库
 * C++17 标准
*/
#include <filesystem>

/**
 * 平台无关类型
*/
#include "xtype.h"

/**
 * @brief 
 * 标准库重命名
 * 
 */
namespace ngStd = std;
namespace ngStdChrono = std::chrono;
namespace ngStdFileSystem = std::filesystem;