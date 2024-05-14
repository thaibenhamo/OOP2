#include "Form.h"

Form::Form() {}

void Form::addField(BaseField* field)
{
	m_fields.push_back(field);
}

void Form::addValidator(FormValidator* formValidator)
{
	m_formValidators.push_back(formValidator);
}


bool Form::validateForm()
{
	bool formIsValid = true;
	for (int i = 0; i < m_fields.size(); i++)
	{
		if (!m_fields[i]->isValid())
		{
			formIsValid = false;
		}
	}

	for (int i = 0; i < m_formValidators.size(); i++)
	{
		if (!m_formValidators[i]->isValid())
		{
			formIsValid = false;
		}
	}
	return formIsValid;
}

void Form::fillForm()
{
	for (int i = 0; i < m_fields.size(); i++)
	{
		if (!m_fields[i]->isValid())
		{
			m_fields[i]->readField();
		}
	}
}

void Form::printFields(std::ostream& os) const
{
	for (int i = 0; i < m_fields.size(); i++)
		m_fields[i]->print(os);
}

std::ostream& operator <<(std::ostream& os, const Form& form)
{
	form.printFields(os);
	return os;
}

