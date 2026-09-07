#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <climits>
#include <fstream>
#include <iomanip>


#ifndef FILE_HEADER_ROW
#define FILE_HEADER_ROW "date | value"
#endif

#ifndef DB
# define DB "data.csv"
#endif

struct Date
{
	int year;
	int month;
	int day;
	
	Date();
	Date(int y, int m, int d);
	Date(const Date& other);


	bool	operator<(const Date& other) const;
	Date	operator-(const Date& other) const;
	Date	abs(void) const;
	bool	checkDate(void) const;
};

std::ostream& operator<<(std::ostream&, const Date&);
