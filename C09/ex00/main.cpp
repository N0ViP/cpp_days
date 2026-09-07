#include "BitcoinExchange.hpp"


bool	checkInputs(Date& date, char seps[3], double& value)
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

double	getValue(std::map<Date, double>& db_map, Date& date)
{
	std::map<Date, double>::iterator r, l;
	l = db_map.lower_bound(date);
	if (l == db_map.end())
		return (--l)->second;

	r = l;
	--l;

	return ((l->first - date).abs() < (r->first - date).abs())? l->second : r->second;
}


void	PrintValue(std::map<Date, double>& db_map, Date& date, double& value)
{
	std::cout << date << " => " << value << " = ";

	double res = getValue(db_map, date) * value;

	std::cout << res << std::endl;


}

bool	ParseFile(std::ifstream& file, std::map<Date, double>& db_map)
{
	std::string line;
	
	if (!std::getline(file, line))
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
		double value;
		char seps[3];
		ss >> date.year >> seps[0] >> date.month >> seps[1] >> date.day >> seps[2] >> value;
		if (!checkInputs(date, seps, value))
			continue;
		PrintValue(db_map, date, value);
	}

	return true;
}

bool	fillDbMap(std::ifstream& db, std::map<Date, double>& db_map)
{
	std::string line;

	if (!std::getline(db, line))
	{
		std::cerr << "Error: getline can't read the database" << std::endl;
		return false;
	}

	while (std::getline(db, line))
	{
		std::stringstream ss(line);
		char	sep;
		Date	date;
		double	value;

		ss >> date.year >> sep >> date.month >> sep >> date.day >> sep >> value;
		db_map.insert(std::pair<Date, double>(date, value));
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

	if (!idb.is_open() || !ifile.is_open())
	{
		idb.close();
		ifile.close();
		return 1;
	}

	std::map<Date, double> idb_map;
	if (!fillDbMap(idb, idb_map))
		return 1;
	
	idb.close();

	ParseFile(ifile, idb_map);

	return 0;
}
