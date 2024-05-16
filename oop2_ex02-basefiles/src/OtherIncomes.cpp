#include "OtherIncomes.h"

OtherIncomes::OtherIncomes() 
    : BaseOptions({ "I have no other income", "Monthly salary" ,"Salary for additional employment",
                    "Partial salary", "Allowance", "Scholarship"} )
{}  

std::string OtherIncomes::optionsToString() const
{
    return ("(1 - I have no other income, 2 - Monthly salary, 3 - Salary for additional\n"
            "employment, 4 - Partial salary, 5 - Allowance, 6 - Scholarship)");
}