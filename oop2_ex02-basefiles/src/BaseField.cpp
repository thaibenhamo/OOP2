#include "BaseField.h"

BaseField::BaseField() 
{}

void BaseField::setReadAgain(bool readAgain)
{
	m_readAgain = readAgain;
}

bool BaseField::needToReadAgain()
{
	return m_readAgain;
}