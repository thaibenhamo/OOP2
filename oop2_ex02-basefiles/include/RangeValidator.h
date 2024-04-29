#pragma once

#include "Validator.h"
#include "Date.h"
#include <string>

template<typename T>
class RangeValidator : public Validator<T>
{
public:
	RangeValidator(const T& min, const T& max);
	virtual ~RangeValidator() = default;
	bool validate(const T& input) const override;
	std::string getErrorMessage() const override;
protected:
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
	return(input >= m_min && input <= m_max);
}

template<typename T>
std::string RangeValidator<T>::getErrorMessage() const
{
	return ("Out of range.\n");
}
