#include "OtherIncomesAndTaxCreditsValidator.h"

OtherIncomesAndTaxCreditsValidator::OtherIncomesAndTaxCreditsValidator(Field<ValuesToNames<OtherIncomes>>* otherIncomes,
    Field<ValuesToNames<TaxCredits>>* taxCredits)
    : m_otherIncomes(otherIncomes), m_taxCredits(taxCredits) {}

void OtherIncomesAndTaxCreditsValidator::printErrorMessage() const
{
    std::cout << "Incomes report and Other incomes report don't match.\n";
}

bool OtherIncomesAndTaxCreditsValidator::isValid() const
{
    int otherIncomesAnswer = m_otherIncomes->getAnswer().getOption();
    int taxCreditsAnswer = m_taxCredits->getAnswer().getOption();

    if (taxCreditsAnswer == 1 && otherIncomesAnswer != 1)
        return false;
    if (taxCreditsAnswer == 2 && (otherIncomesAnswer == 1 || otherIncomesAnswer > 4))
        return false;
    //m_otherIncomes
    //m_taxCredits.setReadAgain(false);
 
    return true;
}