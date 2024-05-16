#include "BaseField.h"

BaseField::BaseField() 
{}

void BaseField::setReadAgain(bool readAgain)
{
	m_readAgain = readAgain;
}

bool BaseField::needToReadAgain() const 
{
	return m_readAgain;
}