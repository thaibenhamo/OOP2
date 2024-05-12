#pragma once

#include <string>
#include <iostream>
#include "BaseField.h"
#include "Validator.h"

template<typename T>
class Field : public BaseField
{
public:
	Field(std::string str);
	void addValidator(Validator<T>* v);	
	void readField();
	bool isValid();
	T getAnswer() const;
protected:
	
	void print(std::ostream& os) const override;
	std::string m_prompt;
	std::string m_errorMessage;
	Validator<T>* m_validator;
	T m_data;
};

template<typename T>
Field<T>::Field(std::string str) 
	: m_prompt(str), m_errorMessage(), m_validator(), m_data(){}

template<typename T>
void Field<T>::addValidator(Validator<T>* v)
{
	m_validator = v;
	m_errorMessage = v->getErrorMessage();
}

template<typename T>
void Field<T>::readField()
{
	std::cout << m_prompt << std::endl;
	std::cin >> m_data;
}

template<typename T>
bool Field<T>::isValid()
{
	if (m_validator->validate(m_data))
	{
		m_valid = true;
	}
	return m_valid;
}
template<typename T>
T Field<T>::getAnswer() const
{
	return m_data;
}

template<typename T>
void Field<T>::print(std::ostream& os) const
{
	os << m_prompt << " = " << m_data;
	if (!m_valid)
		os << "		" << m_errorMessage;
	else
		os << '\n';
}	