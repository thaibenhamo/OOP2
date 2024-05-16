#pragma once

#include "FormValidator.h"
#include "Field.h"
#include "ValuesToNames.h"
#include "OtherIncomes.h"
#include "TaxCredits.h"

class OtherIncomesAndTaxCreditsValidator : public FormValidator
{
public:
    OtherIncomesAndTaxCreditsValidator(Field<ValuesToNames<OtherIncomes>>* otherIncomes, 
                                       Field<ValuesToNames<TaxCredits>>* taxCredits);
private:
    virtual void printErrorMessage(std::ostream& os) const override;
    virtual bool isValid() override;
    Field<ValuesToNames<OtherIncomes>>* m_otherIncomes;
    Field<ValuesToNames<TaxCredits>>* m_taxCredits;
};