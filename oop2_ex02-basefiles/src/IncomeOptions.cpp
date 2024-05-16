#include "IncomeOptions.h"

IncomeOptions::IncomeOptions()
    : BaseOptions({ { 1, "Monthly salary" },
                    { 2, "Partial salary" },
                    { 3, "Allowance" },
                    { 4, "Scholarship" } })
{}

std::string IncomeOptions::optionsToString() const
{
    return ("(1 - Monthly salary, 2 - Partial salary, 3 - Allowance, 4 - Scholarship)");
}