#pragma once

#include <regex>

class AddressPattern
{
public:
    static const std::regex& getPattern() 
    { 
        static const std::regex pattern(R"([a-zA-Z]+-\d+-[a-zA-Z]+)");
        return pattern;
    }
private:
};