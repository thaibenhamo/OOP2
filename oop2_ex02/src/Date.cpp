#include "Date.h"

Date::Date( unsigned int year,unsigned int month, unsigned int day) 
	: m_year(year), m_month(month), m_day(day)
{}

unsigned int Date::getYear() const
{
	return m_year;
}

unsigned int Date::getMonth() const
{
	return m_month;
}
unsigned int Date::getDay() const
{
	return m_day;
}

void Date::setYear(unsigned int& year) 
{
	m_year = year;
}

void Date::setMonth(unsigned int& month)
{
	m_month = month;
}

void Date::setDay(unsigned int& day)
{
	m_day = day;
}


Date operator-(const Date& date1, const int& maxAge)
{
	unsigned int year = date1.getYear() - maxAge;
	unsigned int month = date1.getMonth();
	unsigned int day = date1.getDay();

	return Date(year,month,day);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

std::istream& operator>>(std::istream& is, Date& date) 
{
    unsigned int year, month, day;

    is >> year;
    is.ignore(1); // Ignore the next character (delimiter)
    is >> month;
    is.ignore(1); // Ignore the next character (delimiter)
    is >> day;
	
	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);

    return is;
}

bool operator<(const Date& date1, const Date& date2) 
{
	if (date1.getYear() != date2.getYear())
		return (date1.getYear() < date2.getYear());

	else if (date1.getMonth() != date2.getMonth())
		return (date1.getMonth() < date2.getMonth());

	else 
		return (date1.getDay() < date2.getDay());
}

bool operator>(const Date& date1, const Date& date2)
{
	return (date2 < date1);
}

bool operator>=(const Date& date1, const Date& date2) 
{
	return !(date1 < date2);
}

