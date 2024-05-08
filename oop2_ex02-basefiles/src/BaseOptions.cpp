#include "BaseOptions.h"

BaseOptions::BaseOptions(const std::unordered_map<int, std::string>& options)
{
	m_options = options;
}

std::string BaseOptions::optionsToString() const
{
    std::string result;
    for (const auto& pair : m_options) 
    {
        result += std::to_string(pair.first) + " - " + pair.second;
    }
    return result;
}

