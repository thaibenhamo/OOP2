#include "OtherIncomesAndTaxCreditsValidator.h"

OtherIncomesAndTaxCreditsValidator::OtherIncomesAndTaxCreditsValidator(Field<ValuesToNames<OtherIncomes>>* otherIncomes,
    Field<ValuesToNames<TaxCredits>>* taxCredits)
    : m_otherIncomes(otherIncomes), m_taxCredits(taxCredits) {}

void OtherIncomesAndTaxCreditsValidator::printErrorMessage(std::ostream& os) const
{
    if(!m_valid)
        os << "Other incomes report and tax credits report don't match.\n";
}

bool OtherIncomesAndTaxCreditsValidator::isValid() 
{
    m_valid = true;
    int otherIncomesAnswer = m_otherIncomes->getAnswer().getOption();
    int taxCreditsAnswer = m_taxCredits->getAnswer().getOption();

    if (taxCreditsAnswer == 1 && otherIncomesAnswer != 1)
        m_valid = false;
    if (taxCreditsAnswer == 2 && (otherIncomesAnswer == 1 || otherIncomesAnswer > 4))
        m_valid = false;

    m_otherIncomes->setReadAgain(!m_valid);
    m_taxCredits->setReadAgain(!m_valid);
 
    return m_valid;
}