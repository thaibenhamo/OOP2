#include "IdValidator.h"

IdValidator::IdValidator()
{}

bool IdValidator::validate(const uint32_t& input) const
{
    int sum = 0;
    int incNum;

    std::string idAsStr = std::to_string(input);

    if (idAsStr.length() != 9)
    {  
        return false;
    }

    for (int i = 0; i < idAsStr.length(); i++)
    {
        incNum = (idAsStr[i] - '0') * ((i % 2) + 1);  
        sum += (incNum > 9) ? incNum - 9 : incNum;
    }
    return(sum % 10 == 0);
}
std::string IdValidator::getErrorMessage() const
{
    return("Wrong control digit.\n");
}