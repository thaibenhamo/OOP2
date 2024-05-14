#include "BaseOptions.h"

BaseOptions::BaseOptions(const std::unordered_map<int, std::string>& options)
{
	m_options = options;
}

std::string BaseOptions::getName(const int value) const
{
    return (!m_options.contains(value) ? "0" : m_options.at(value));
}

