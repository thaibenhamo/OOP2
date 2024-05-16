#include "BaseOptions.h"

BaseOptions::BaseOptions(const std::vector<std::string>& options)
    : m_options(options) {}

std::string BaseOptions::getName(int value) const 
{
    if (value >= 0 && value < m_options.size()) 
        return m_options[value-1];

    return std::to_string(value);
}