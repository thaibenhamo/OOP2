#pragma once
#include <vector>
#include <iostream>
#include "BaseField.h"
#include "FormValidator.h"

class Form
{
public:
	Form();
	void addField(BaseField* field);
	void addValidator(FormValidator *formValidator);
	void printFields(std::ostream& os) const;
	void fillForm();
	bool validateForm();
private:
	std::vector <FormValidator*> m_formValidators;
	std::vector <BaseField*> m_fields;
};

std::ostream& operator <<(std::ostream& os, const Form& form);