#pragma once
//#include <string>
#include "BaseField.h"


class FormValidator
{
public:
	FormValidator() = default;
	virtual ~FormValidator() = default;
	virtual bool isValid() const = 0;
protected:
	virtual void printErrorMessage() const = 0;
	
	
};
