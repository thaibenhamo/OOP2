#pragma once

#include<string>
#include "BaseOptions.h"

class TaxCredits : public BaseOptions
{
public:
	TaxCredits();
	virtual std::string optionsToString() const override;
private:
};