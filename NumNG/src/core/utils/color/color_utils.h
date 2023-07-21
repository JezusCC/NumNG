#pragma once
#include "../common/common.h"
#include "../FPM/fpm_utils.h"

namespace ngUtils {
	class Color :public UtilBase {
	public:
		Color(float32 r, float32 g, float32 b, float32 a);
		Color(const Color& color);

		~Color() = default;

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
}