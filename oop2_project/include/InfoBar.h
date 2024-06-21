#pragma once
#include "Resources.h"

class Infobar
{
public:
	Infobar();
	virtual ~Infobar() = default;

	const int getLevelNum() const;

private:
	int m_levelNum = 1;			// to store level number
};