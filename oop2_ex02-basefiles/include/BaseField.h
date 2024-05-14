#pragma once
#include <string>

class BaseField
{
public:
	BaseField();
	virtual ~BaseField() = default;
	virtual void readField() = 0;
	virtual bool isValid() = 0;
	virtual void print(std::ostream& os) const = 0;
	virtual void setReadAgain(bool readAgain);
	virtual bool needToReadAgain();
protected:
	bool m_valid = false;
	bool m_readAgain = false;
};