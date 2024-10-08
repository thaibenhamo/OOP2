#include "TaxCredits.h"

TaxCredits::TaxCredits()
    : BaseOptions({ { 1, "I have no other income" },
                    { 2, "I request to receive tax credits for this income"},
                    { 3, "I do not request to receive tax credits" } })
{}

std::string TaxCredits::optionsToString() const
{
    return ("(1 - I have no other income, 2 - I request to receive tax credits for this\n"
            "income, 3 - I do not request to receive tax credits)");
}