#include "./color_utils.h"

namespace ngUtils {
	Color::Color(float32 r, float32 g, float32 b, float32 a)
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

	void Color::setColor(float32 r, float32 g, float32 b, float32 a)
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

	float32 Color::getR() const
	{
		return m_r;
	}

	float32 Color::getG() const
	{
		return m_g;
	}

	float32 Color::getB() const
	{
		return m_b;
	}

	float32 Color::getA() const
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
		constexpr float32 epsilon = 0.000001f;
		flag = ngFpm::isEqual(m_r, color.m_r, epsilon) && ngFpm::isEqual(m_g, color.m_g, epsilon)
			&& ngFpm::isEqual(m_b, color.m_b, epsilon) && ngFpm::isEqual(m_a, color.m_a, epsilon);
		return flag == false;
	}

	ngBool Color::operator==(const Color& color) const
	{
		ngBool flag = true;
		constexpr float32 epsilon = 0.000001f;
		flag = ngFpm::isEqual(m_r, color.m_r, epsilon) && ngFpm::isEqual(m_g, color.m_g, epsilon)
			&& ngFpm::isEqual(m_b, color.m_b, epsilon) && ngFpm::isEqual(m_a, color.m_a, epsilon);
		return flag == true;
	}
}