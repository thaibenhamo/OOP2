#pragma once

template<typename T>
class RangeValidator
{
public:
	RangeValidator();
	virtual ~RangeValidator() = default;
private:
};

template<typename T>
RangeValidator<T>::RangeValidator()
{}