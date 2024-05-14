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
    virtual void printErrorMessage() const override;
    virtual bool isValid() const override;
private:
    Field<ValuesToNames<OtherIncomes>>* m_otherIncomes;
    Field<ValuesToNames<TaxCredits>>* m_taxCredits;
};