#pragma once

#include<string>
#include <unordered_map>

class BaseOptions
{
public:
    BaseOptions(const std::unordered_map<int, std::string>& options);
    virtual ~BaseOptions() = default;
    virtual std::string getName(const int value) const;
    std::string optionsToString() const;
protected:
    std::unordered_map<int, std::string> m_options;
};