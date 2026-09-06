#include "BitcoinExchange.hpp"


bool	checkInputs(Date& date, char[3] seps, float& value)
{
	if (!date.checkDate())
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

float	getValue(std::map<Date, float>& db_map, Date& date)
{
	std::map<Date, float>iterator right, left;
	it = db_map.lower_bound(date);
	if (it == db_map.end())
		return (--it)->second;

	left = right - 1;

	return ((left->first - date).abs() < (right->first - date).abs())? left->second : right->second;
}


void	PrintValue(std::map<Date, float>& db_map, Date& date, float& value)
{
	std::cout << date.year << '-' << date.month << '-' << date.day
				<< " => " << value << " = ";

	float res = getValue(db_map, date) * value;

	std::cout << res << std::endl;


}

bool	ParseFile(std::ifstream file, std::map<Date, float>& db_map)
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
		Date date;
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

	std::map<Date, float> ifile_mp, idb_map;

	if (!idb.is_open() || !ifile.is_open())
	{
		idb.close();
		ifile.close();
		return 1;
	}

	fillDbMap(idb, idb_map);

	return 0;
}
