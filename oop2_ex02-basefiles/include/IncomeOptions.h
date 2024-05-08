#pragma once
#include "BaseOptions.h"
#include<string>


class IncomeOptions : public BaseOptions
{
public:
    IncomeOptions();
    virtual std::string getName(const int value) const override;
protected:
};


