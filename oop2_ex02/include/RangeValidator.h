#pragma once

#include <string>
#include "Validator.h"

template<typename T>
class RangeValidator : public Validator<T>
{
public:
	RangeValidator(const T& min, const T& max);
	virtual ~RangeValidator() = default;	
protected:
	bool validate(const T& input) const override;
	std::string getErrorMessage() const override;

	T m_min;
	T m_max;
};

template<typename T>
RangeValidator<T>::RangeValidator(const T& min, const T& max)
{
	m_min = min;
	m_max = max;
}

template<typename T>
bool RangeValidator<T>::validate(const T& input) const
{
	return(input >= m_min && m_max >= input);
}

template<typename T>
std::string RangeValidator<T>::getErrorMessage() const
{
	return ("Out of range");
}
