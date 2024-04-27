#include "Form.h"

Form::Form() {}

void Form::addField(BaseField* f)
{
	m_fields.push_back(f);
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

