#pragma once
#include <iostream>

class Date
{
public:
	Date(const unsigned int& year = 0, const unsigned int& month = 0, const unsigned int& day = 0);
	//Date();
	virtual ~Date() = default;
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;

private:
	unsigned int m_year;
	unsigned int m_month;
	unsigned int m_day;
};

Date operator-(const Date& date1, const Date& date2);

std::ostream& operator<<(std::ostream& os, const Date& date);