#include <regex>

class NamePattern 
{
public:
    static const std::regex& getPattern() 
    {
        static const std::regex pattern(R"(\b[A-Za-z\s'-]+\b)");
        return pattern;
    }
};