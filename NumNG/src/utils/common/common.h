#pragma once
#include "../../preclude/preclude.h"

namespace ngUtils {

	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* 工具基类提供的toString方法，所有工具类均需要实现各自的toString方法
		*/
		virtual ngString toString() = 0;
	};

	/**
	 * 将基类指针转换成子类指针
	 * 若转换成功返回该指针，否则返回空
	 */
	template<typename TargetType, typename SourceType>
	TargetType* DynamicCast(SourceType* source) {
		return dynamic_cast<TargetType*>(source);
	}
	/**
	 * 将源指针转换成目标指针
	 * 若转换成功返回该指针，否则返回空
	 */
	template<typename TargetType, typename SourceType>
	TargetType* ForceCast(SourceType* source) {
		return static_cast<TargetType*>(source);
	}

// 定义一个宏，用于检测成员函数是否存在
#define NG_HAS_MEMBER_HELPER(member) \
    template<typename T, typename... Args> \
    struct ClassHasMember_##member \
    { \
    private: \
        template<typename U> \
        static auto check(int) -> decltype(std::declval<U>().member(std::declval<Args>()...), std::true_type()); \
        template<typename U> \
        static std::false_type check(...); \
    public: \
        static constexpr bool value = decltype(check<T>(0))::value; \
    };

#define NG_CLASS_HAS_MEMBER_FUNCTION(_Class,_Function) ClassHasMember_##_Function<_Class>::value

	/**
	 * 定义isEmpty作为下面isEmpty函数的校验类
	 */
	NG_HAS_MEMBER_HELPER(isEmpty);
	NG_HAS_MEMBER_HELPER(empty);

	/**
	 * @brief 返回目标是否为空
	 * 
	 * @tparam T 
	 * @param val 对象
	 * @return ngBool 
	 */
	template<typename T>
	ngBool isEmpty(T val){	

		if constexpr(ngStd::is_pointer<T>::value){	//指针
			return val == nullptr;
		}else if constexpr(ngStd::is_same<T,ngString>::value){	//字符串
			return val == "";
		}else if constexpr(ngStd::is_class<T>::value){	//类
			if constexpr(NG_CLASS_HAS_MEMBER_FUNCTION(T,isEmpty)){
				return val.isEmpty();
			}else if constexpr(NG_CLASS_HAS_MEMBER_FUNCTION(T,empty)){
				return val.empty();
			}else{
				ngStd::cout << "class has not implements isEmpty or empty function." << ngStd::endl;
				return true;
			}
		}else{
			ngStd::cout << "can not to check val type,only support type:[pointer/string/and class with implements member function:isEmpty or empty]";
			return true;
		}
	}

	/**
	 * @brief 返回目标是否非空
	 *
	 * @tparam T
	 * @param val 对象
	 * @return ngBool
	 */
	template<typename T>
	ngBool isNotEmpty(T val) {
		return !isEmpty<T>(val);
	}
}