#include "utils.h"

namespace ngUtil {
	Hash::Hash(ngInt value)
	{
		std::stringstream ss;
		ss << value;
		std::hash<ngString> hasher;
		this->m_code = hasher(ss.str());
	}

	Hash::Hash(ngString value)
	{
		std::hash<ngString> hasher;
		this->m_code = hasher(value);
	}
	ngBool Hash::operator==(const Hash& value) const
	{
		return this->m_code == value.m_code;
	}
	ngBool Hash::operator!=(const Hash& value) const
	{
		return this->m_code != value.m_code;
	}
	ngInt Hash::getCode() const
	{
		return m_code;
	}
	ngString Hash::toString()
	{
		std::stringstream ss;
		ss << m_code;
		ngString ret = ss.str();
		return ret;
	}
	UUID::UUID()
	{
		std::random_device rd;
		std::uniform_int_distribution<uint64_t> dist(0ULL, 0xFFFFFFFFFFFFFFFFULL);
		uint64_t ab = dist(rd);
		uint64_t cd = dist(rd);
		uint32_t a, b, c, d;
		std::stringstream ss;
		ab = (ab & 0xFFFFFFFFFFFF0FFFULL) | 0x0000000000004000ULL;
		cd = (cd & 0x3FFFFFFFFFFFFFFFULL) | 0x8000000000000000ULL;
		a = (ab >> 32U);
		b = (ab & 0xFFFFFFFFU);
		c = (cd >> 32U);
		d = (cd & 0xFFFFFFFFU);
		ss << std::hex << std::nouppercase << std::setfill('0');
		ss << std::setw(8) << (a) << '-';
		ss << std::setw(4) << (b >> 16U) << '-';
		ss << std::setw(4) << (b & 0xFFFFU) << '-';
		ss << std::setw(4) << (c >> 16U) << '-';
		ss << std::setw(4) << (c & 0xFFFFU);
		ss << std::setw(8) << d;
		
		this->m_id = ss.str();
	}
	ngBool UUID::operator==(const UUID& value) const
	{
		return this->m_id == value.m_id;
	}
	ngBool UUID::operator!=(const UUID& value) const
	{
		return this->m_id != value.m_id;
	}
	ngString UUID::getUUID() const
	{
		return this->m_id;
	}
	ngString UUID::toString()
	{
		return this->m_id;
	}
}
