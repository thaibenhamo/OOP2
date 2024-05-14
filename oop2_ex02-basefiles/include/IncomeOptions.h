#pragma once
#include "BaseOptions.h"
#include<string>


class IncomeOptions : public BaseOptions
{
public:
    IncomeOptions();
    virtual std::string optionsToString() const override;
private:
};


