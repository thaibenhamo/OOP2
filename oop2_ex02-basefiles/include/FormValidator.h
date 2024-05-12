#pragma once
#include <string>
#include "BaseField.h"


class FormValidator
{
public:
	FormValidator() = default;
	virtual ~FormValidator() = default;
protected:
	virtual std::string getErrorMessage() const = 0;
	virtual bool validate() const = 0;
	
};
