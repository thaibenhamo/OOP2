#pragma once
#include "BaseOptions.h"
#include<string>


class OtherIncomes : public BaseOptions
{
public:
	OtherIncomes();
	virtual std::string optionsToString() const override;
private:
};
