#include "RegexValidator.h"

RegexValidator::RegexValidator(const std::regex& pattern) 
	: m_pattern(pattern) {}

bool RegexValidator::validate(const std::string& input) const
{
    return std::regex_match(input, m_pattern);
}

std::string RegexValidator::getErrorMessage() const
{
	return("The input does not adhere to the expected format.\n");
}