#pragma once

template<typename T>
class Validator
{
public:
	Validator() {};
	virtual ~Validator() = default;
	virtual std::string getErrorMessage() const = 0;
	virtual bool validate(const T& input) const = 0;
protected:
};