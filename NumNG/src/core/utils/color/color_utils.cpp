#include "./color_utils.h"
//#include <string>

namespace ngUtils {
	Color::Color(ngFloat r, ngFloat g, ngFloat b, ngFloat a)
	{
		m_r = r;
		m_g = g;
		m_b = b;
		m_a = a;
	}

	Color::Color(const Color& color)
	{
		m_r = color.m_r;
		m_g = color.m_g;
		m_b = color.m_b;
		m_a = color.m_a;
	}

	void Color::setColor(ngFloat r, ngFloat g, ngFloat b, ngFloat a)
	{
		m_r = r;
		m_g = g;
		m_b = b;
		m_a = a;
	}

	void Color::setColor(const Color& color)
	{
		m_r = color.m_r;
		m_g = color.m_g;
		m_b = color.m_b;
		m_a = color.m_a;
	}

	ngFloat Color::getR() const
	{
		return m_r;
	}

	ngFloat Color::getG() const
	{
		return m_g;
	}

	ngFloat Color::getB() const
	{
		return m_b;
	}

	ngFloat Color::getA() const
	{
		return m_a;
	}

	ngString Color::toString()
	{
		std::stringstream ss;
		ss << "Color(r:" << m_r << " g:" << m_g << " b:" << m_b << " a:" << m_a << ")";
		return ss.str();
	}

	ngBool Color::operator!=(const Color& color) const
	{
		ngBool flag = false;
		constexpr ngFloat epsilon = 0.000001f;
		flag = ngFpm::isEqual(m_r, color.m_r, epsilon) && ngFpm::isEqual(m_g, color.m_g, epsilon)
			&& ngFpm::isEqual(m_b, color.m_b, epsilon) && ngFpm::isEqual(m_a, color.m_a, epsilon);
		return flag == false;
	}

	ngBool Color::operator==(const Color& color) const
	{
		ngBool flag = true;
		constexpr ngFloat epsilon = 0.000001f;
		flag = ngFpm::isEqual(m_r, color.m_r, epsilon) && ngFpm::isEqual(m_g, color.m_g, epsilon)
			&& ngFpm::isEqual(m_b, color.m_b, epsilon) && ngFpm::isEqual(m_a, color.m_a, epsilon);
		return flag == true;
	}
	uint64 _ng_str_to_hex(ngString value)
	{
		uint64 val;
		std::stringstream ss;
		ss << std::hex << value;
		ss >> val;
		//val = std::stoll("0x" + value, 0, 16);
		return val;
	}
	Color ParseStrToColor(ngString str)
	{
		try {
			int32 len = str.size();
			if (str[0] != '#') {
				throw std::exception("Invalid Color Format");
			}
			ngString rstr;
			ngString gstr;
			ngString bstr;
			ngString astr;
			ngFloat r;
			ngFloat g;
			ngFloat b;
			ngFloat a;
			if (len == 4) {
				//#fff
				rstr.push_back(str[1]);
				rstr.push_back(str[1]);
				gstr.push_back(str[2]);
				gstr.push_back(str[2]);
				bstr.push_back(str[3]);
				bstr.push_back(str[3]);
				astr += "ff";
			}
			else if (len == 7) {
				rstr.push_back(str[1]);
				rstr.push_back(str[2]);
				gstr.push_back(str[3]);
				gstr.push_back(str[4]);
				bstr.push_back(str[5]);
				bstr.push_back(str[6]);
				astr += "ff";
			}
			else if (len == 9) {
				rstr.push_back(str[1]);
				rstr.push_back(str[2]);
				gstr.push_back(str[3]);
				gstr.push_back(str[4]);
				bstr.push_back(str[5]);
				bstr.push_back(str[6]);
				astr.push_back(str[7]);
				astr.push_back(str[8]);
			}
			else {
				throw std::exception("Invalid Color Format");
			}
			std::stringstream ss;

			r = ngFpm::NumricMapping<ngFloat>(_ng_str_to_hex(rstr), 0, 255, 0.0, 1.0);
			g = ngFpm::NumricMapping<ngFloat>(_ng_str_to_hex(gstr), 0, 255, 0.0, 1.0);
			b = ngFpm::NumricMapping<ngFloat>(_ng_str_to_hex(bstr), 0, 255, 0.0, 1.0);
			a = ngFpm::NumricMapping<ngFloat>(_ng_str_to_hex(astr), 0, 255, 0.0, 1.0);

			return Color(r, g, b, a);
		}
		catch (std::exception& e) {
			std::cout << "Utils Error:" << e.what() << std::endl;
		}
	}
}