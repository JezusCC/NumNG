#pragma once
#include "../common/common.h"
#include "../FPM/fpm_utils.h"

namespace ngUtils {
	class Color :public UtilBase {
	public:
		Color(ngFloat r, ngFloat g, ngFloat b, ngFloat a);
		Color(const Color& color);

		~Color() = default;

		void setColor(ngFloat r, ngFloat g, ngFloat b, ngFloat a);
		void setColor(const Color& color);

		ngFloat getR()const;
		ngFloat getG()const;
		ngFloat getB()const;
		ngFloat getA()const;

		ngBool operator==(const Color& color)const;
		ngBool operator!=(const Color& color)const;

		ngString toString()override;
	private:
		ngFloat m_r;
		ngFloat m_g;
		ngFloat m_b;
		ngFloat m_a;
	};


	uint64 _ng_str_to_hex(ngString value);

	Color ParseStrToColor(ngString str);
}