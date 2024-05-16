#pragma once

#include<string>
#include "BaseOptions.h"

class OtherIncomes : public BaseOptions
{
public:
	OtherIncomes();
	virtual std::string optionsToString() const override;
private:
};
