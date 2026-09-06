#include "BitcoinExchange.hpp"

Date::Date(int y, int m, int d): year(y), month(m), day(d) {}
Date::Date(const Date& other): year(other.year), month(other.month), day(other.day) {}
bool	Date::operator<(const Date& other) const
{
	if (year != other.year)
		return year < other.year;

	if (month != second.month)
		return month < other.month;

	return day < other.day;
}

Date	Date::operator-(const Date& other) const
{
	return (Date(year - other.year, month - other.month, day - other.day));
}

Date	Date::abs(void) const
{
	Date res(*this);

	if (res.year < 0)
		res.year = -(res.year);
	if (res.month < 0)
		res.month = -(res.mont);
	if (res.day < 0)
		res.day = -(res.day);

	return res;
}


bool Date::checkDate(void) const
{
	char DaysOfMonths[] = {31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31};
	bool isLeapYear;

	isLeapYear = ((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0);
	DaysOfMonths[1] += isLeapYear;

	if (year < 0 || !(month >= 1 && month <= 12) || DaysOfMonths[month - 1] >= day)
	{
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}

	return true;
}
