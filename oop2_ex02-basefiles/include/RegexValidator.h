#include <regex>
#include <memory>
#include <string>
#include "Validator.h"

class RegexValidator : public Validator<std::string>
{
public:
    RegexValidator(const std::regex& pattern);
    bool validate(const std::string& input) const;
    std::string getErrorMessage() const;
private:
    std::regex m_pattern;
};
