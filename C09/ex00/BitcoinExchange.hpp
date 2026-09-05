#pragma once

#include <iostream>
#include <map>

#ifndef DB_HEADER_ROW
#define DB_HEADER_ROW "date,exchange_rate"
#endif

#ifndef FILE_HEADER_ROW
#define FILE_HEADER_ROW "date | value"
#endif

#ifndef DB
# define DB "data.csv"
#endif

typedef struct s_date
{
	int year;
	int month;
	int day;
}	t_date;


