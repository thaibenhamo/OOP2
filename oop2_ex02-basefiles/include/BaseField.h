#pragma once
#include <string>
#include "Validator.h"

class BaseField
{
public:
	BaseField();
	virtual ~BaseField() = default;
	//virtual bool isValid() const;
	virtual void readField() = 0;
	virtual bool isValid() = 0;
	virtual void print(std::ostream& os)= 0;
protected:
	//bool m_empty = true;
	bool m_valid = false;
};