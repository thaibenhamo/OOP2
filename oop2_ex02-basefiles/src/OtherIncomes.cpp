#include "OtherIncomes.h"

OtherIncomes::OtherIncomes() 
    : BaseOptions({ { 1, "I have no other income"},
                    { 2, "Monthly salary" },
                    { 3, "Salary for additional employment"},
                    { 4, "Partial salary" },
                    { 5, "Allowance" },
                    { 6, "Scholarship"} })
{}  

std::string OtherIncomes::optionsToString() const
{
    return ("(1 - I have no other income, 2 - Monthly salary, 3 - Salary for additional\n"
            "employment, 4 - Partial salary, 5 - Allowance, 6 - Scholarship)");
}