#include "BaseOptions.h"

BaseOptions::BaseOptions(const std::unordered_map<int, std::string>& options)
{
	m_options = options;
}

std::string BaseOptions::optionsToString() const
{
    std::string result = "(";
    int size = m_options.size();
    int count = 0;

    for (const auto& pair : m_options)
    {
        result += std::to_string(pair.first) + " - " + pair.second;
     
        if (++count < size) 
        {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

std::string BaseOptions::getName(const int value) const
{
    return (!m_options.contains(value) ? "0" : m_options.at(value));
}

