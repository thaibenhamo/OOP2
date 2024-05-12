#include "IncomesAndOtherIncomesValidator.h"

IncomesAndOtherIncomesValidator::IncomesAndOtherIncomesValidator(Field<ValuesToNames<IncomeOptions>>* incomes, 
    Field<ValuesToNames<OtherIncomes>>* otherIncomes)
    : m_incomes(incomes), m_otherIncomes(otherIncomes) {}

std::string IncomesAndOtherIncomesValidator::getErrorMessage() const
{
    return("Incomes report and Other incomes report don't match.\n");
}

bool IncomesAndOtherIncomesValidator::validate() const
{
    int incomesAnswer = m_incomes->getAnswer().getOption();
    int otherIncomesAnswer = m_otherIncomes->getAnswer().getOption();

    if (incomesAnswer == 4 && otherIncomesAnswer == 6)
        return false;
    if (incomesAnswer == 3 && otherIncomesAnswer == 5)
        return false;
    if (!(incomesAnswer == 1 || incomesAnswer == 2) && otherIncomesAnswer == 3)
        return false;

    return true;
}