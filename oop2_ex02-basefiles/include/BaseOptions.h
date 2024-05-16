#pragma once

#include <string>
#include <vector>

class BaseOptions
{
public:
    BaseOptions(const std::vector<std::pair<int, std::string>>& options);
    virtual ~BaseOptions() = default;
    virtual std::string getName(const int value) const;
    virtual std::string optionsToString() const = 0;
protected:
    std::vector<std::pair<int, std::string>> m_options;
};