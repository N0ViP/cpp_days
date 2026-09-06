#include "BitcoinExchange.hpp"

bool checkDate(t_date& date)
{
	char DaysOfMonths[] = {31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31};
	bool isLeapYear;

	isLeapYear = ((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0);
	DaysOfMonths[1] += isLeapYear;

	if (date.year < 0
		|| !(date.month >= 1 && date.month <= 12)
		|| DaysOfMonths[date.month - 1] >= date.day)
	{
		std::cerr << "Error: invalid date" << std::endl;
		return false;
	}

	return true;
}

bool	checkInputs(t_date& date, char[3] seps, float& value)
{
	if (!checkDate(date))
		return false;
	if (seps[0] != '-' || seps[1] != '-' || seps[2] != '|')
	{
		std::cerr << "Error: invalid separator" << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return false;
	}
	else if (value > INT_MAX)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	return true;
}


void	PrintValue(std::map<t_date, float>& db_map, t_date& date, float& value)
{
	std::cout << date.year << '-' << date.month << '-' << date.day
				<< " => " << value << " = ";
	float res;


}

bool	ParseFile(std::ifstream file, std::map<t_date, float>& db_map)
{
	std::string line;
	
	if (std::getline(file, line))
	{
		std::cerr << "Error: getline can't read the file" << std::endl;
		return false;
	}

	{
		std::string HeaderColm1, HeaderColm2;
		char sep;
		std::stringstream ss(line);
		ss >> HeaderColm1 >> sep >> HeaderColm2;
		if (HeaderColm1 != "date" || sep != '|' || HeaderColm2 != "value")
		{
			std::cerr << "Error: invalid inputs" << std::endl;
			return false;	
		}
	}

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		t_date date;
		float value;
		char seps[3]0;
		ss >> date.year >> seps[0] >> date.month >> seps[1] >> date.day >> seps[2] >> value;
		if (!checkInputs(date, seps, value))
			continue;
		PrintValue(db_map, date, value);
	}

	return true;
}

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc input.txt" << std::endl;
		return 0;
	}

	std::ifstream ifile(av[1]);
	std::ifstream idb(DB);

	std::map<t_date, float> ifile_mp, idb_map;

	if (!idb.is_open() || !ifile.is_open())
	{
		idb.close();
		ifile.close();
		return 1;
	}

	if (!ParseFile(idb_map, idb_map, DB_HEADER_ROW) || !ParseFile(ifile_mp, ifile, FILE_HEADER_ROW))
	{
		return 2;
	}

	return 0;
}
