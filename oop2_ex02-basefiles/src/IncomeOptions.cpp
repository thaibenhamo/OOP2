#include "IncomeOptions.h"

IncomeOptions::IncomeOptions()
    : BaseOptions({ { 1, "Monthly salary" },
                   { 2, "Partial salary" },
                   { 3, "Allowance" },
                   { 4, "Scholarship" } })
{}

std::string IncomeOptions::getName(const int value) const
{
    return (!m_options.contains(value) ? "0" : m_options.at(value));
}