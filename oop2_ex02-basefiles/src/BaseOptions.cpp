#include "BaseOptions.h"

BaseOptions::BaseOptions(const std::vector<std::pair<int, std::string>>& options)
    : m_options(options) {}

std::string BaseOptions::getName(const int value) const
{
    for (const auto& option : m_options) 
    {
        if (option.first == value) 
            return option.second;    
    }
    return std::to_string(value);
}