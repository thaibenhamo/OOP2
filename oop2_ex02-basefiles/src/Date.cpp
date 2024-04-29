#include "Date.h"

Date::Date(const unsigned int& year, const unsigned int& month, const unsigned int& day) 
	: m_year(year), m_month(month), m_day(day)
{}

/*Date::Date()
	: m_year(0), m_month(0), m_day(0)
{}*/

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

Date operator-(const Date& date1, const Date& date2)
{
	unsigned int year = date1.getYear() - date2.getYear();
	unsigned int month = date1.getMonth() - date2.getMonth();
	unsigned int day = date1.getDay() - date2.getDay();

	return Date(year,month,day);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

