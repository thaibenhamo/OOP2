#pragma once

#include <string>
#include <vector>

class BaseOptions {
public:
    BaseOptions(const std::vector<std::string>& options);
    virtual ~BaseOptions() = default;
    virtual std::string getName(int value) const;
    virtual std::string optionsToString() const = 0;
protected:
    std::vector<std::string> m_options;
};