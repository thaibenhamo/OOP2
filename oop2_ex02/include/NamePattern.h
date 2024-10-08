#pragma once

#include <regex>

class NamePattern 
{
public:
    static const std::regex& getPattern() 
    {
        static const std::regex pattern(R"([^0-9]+)");
        return pattern;
    }
private:
};