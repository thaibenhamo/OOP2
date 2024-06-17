#pragma once
#include "Resources.h"

class Infobar
{
public:
	Infobar();
	virtual ~Infobar() = default;

	Infobar(const Infobar&) = default;
	Infobar& operator=(const Infobar&) = default;
	Infobar(Infobar&&) = default;
	Infobar& operator=(Infobar&&) = default;

	const int getLevelNum() const;

private:

	int m_levelNum = 1;			// to store level number
};