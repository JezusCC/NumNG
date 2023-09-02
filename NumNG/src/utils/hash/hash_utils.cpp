#include "./hash_utils.h"

namespace ngUtils {
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
}