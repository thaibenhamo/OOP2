#pragma once

#include "BaseField.h"

class FormValidator
{
public:
	FormValidator() {};
	virtual ~FormValidator() = default;
	virtual bool isValid() = 0;
	virtual void printErrorMessage(std::ostream& os) const = 0;
protected:
	bool m_valid = true;
};
