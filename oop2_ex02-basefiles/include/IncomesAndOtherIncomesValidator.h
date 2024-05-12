#pragma once
#include "FormValidator.h"
#include "Field.h"
#include "ValuesToNames.h"
#include "IncomeOptions.h"
#include "OtherIncomes.h"

class IncomesAndOtherIncomesValidator : public FormValidator
{
public:
    IncomesAndOtherIncomesValidator(Field<ValuesToNames<IncomeOptions>>* incomes, Field<ValuesToNames<OtherIncomes>>* otherIncomes);
    virtual std::string getErrorMessage() const override;
    virtual bool validate() const override;
private:
    Field<ValuesToNames<IncomeOptions>>* m_incomes;
    Field<ValuesToNames<OtherIncomes>>* m_otherIncomes;
};