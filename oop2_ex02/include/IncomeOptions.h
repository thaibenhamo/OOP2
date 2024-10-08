#pragma once

#include<string>
#include "BaseOptions.h"

class IncomeOptions : public BaseOptions
{
public:
    IncomeOptions();
    virtual std::string optionsToString() const override;
private:   
};


