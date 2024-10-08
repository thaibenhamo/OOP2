#pragma once

#include <regex>

class MailPattern
{
public:
    static const std::regex& getPattern()
    {
        static const std::regex pattern(R"([a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z]{2,})");
        return pattern;
    }
private:
};