#pragma once
#include "BaseOptions.h"
#include<string>

class TaxCredits : public BaseOptions
{
public:
	TaxCredits();
	virtual std::string optionsToString() const override;
private:
};