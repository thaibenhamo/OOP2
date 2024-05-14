#include "IncomesAndOtherIncomesValidator.h"

IncomesAndOtherIncomesValidator::IncomesAndOtherIncomesValidator(Field<ValuesToNames<IncomeOptions>>* incomes, 
    Field<ValuesToNames<OtherIncomes>>* otherIncomes)
    : m_incomes(incomes), m_otherIncomes(otherIncomes) {}

void IncomesAndOtherIncomesValidator::printErrorMessage(std::ostream& os) const
{
    if(!m_valid)
        os << "Incomes report and Other incomes report don't match.\n";
}

bool IncomesAndOtherIncomesValidator::isValid()
{
    m_valid = true;
    int incomesAnswer = m_incomes->getAnswer().getOption();
    int otherIncomesAnswer = m_otherIncomes->getAnswer().getOption();

    if (incomesAnswer == 4 && otherIncomesAnswer == 6)
        m_valid = false;
    if (incomesAnswer == 3 && otherIncomesAnswer == 5)
        m_valid =  false;
    if (!(incomesAnswer == 1 || incomesAnswer == 2) && otherIncomesAnswer == 3)
        m_valid =  false;
   
    m_incomes->setReadAgain(!m_valid);
    m_otherIncomes->setReadAgain(!m_valid);

    return m_valid;
}