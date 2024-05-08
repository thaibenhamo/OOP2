#pragma once
#include <iostream>

class Date
{
public:
	Date(unsigned int year = 0, unsigned int month = 1, unsigned int day = 1);
	virtual ~Date() = default;
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	void setYear(unsigned int& year);
	void setMonth(unsigned int& month);
	void setDay(unsigned int& day);

private:
	unsigned int m_year;
	unsigned int m_month;
	unsigned int m_day;
};

Date operator-(const Date& date1, const int& maxAge);

std::ostream& operator<<(std::ostream& os, const Date& date);

std::istream& operator>>(std::istream& is, Date& date);

bool operator<(const Date& date1, const Date& date2);

bool operator>(const Date& date1, const Date& date2);

bool operator>=(const Date& date1, const Date& date2);

//bool operator<=(const Date & date1, const Date & date2);