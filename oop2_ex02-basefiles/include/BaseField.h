#pragma once
#include <string>
#include "Validator.h"

class BaseField
{
public:
	BaseField();
	virtual ~BaseField() = default;
	virtual void readField() = 0;
	virtual bool isValid() = 0;
	virtual void print(std::ostream& os) const = 0;
protected:
	bool m_valid = false;
};