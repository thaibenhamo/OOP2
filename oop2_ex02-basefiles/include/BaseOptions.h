#pragma once

#include<string>
#include <unordered_map>

class BaseOptions
{
public:
    BaseOptions(const std::unordered_map<int, std::string>& options);
    virtual ~BaseOptions() = default;
    virtual std::string getName(const int value) const;
    virtual std::string optionsToString() const = 0;
protected:
    std::unordered_map<int, std::string> m_options;
};