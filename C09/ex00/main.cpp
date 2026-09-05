#include "BitcoinExchange.hpp"



bool	ParseFile(std::ifstream file, std::map<t_date, int>& db_map)
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
		char seps[3] = 0;
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

	std::map<t_date, int> ifile_mp, idb_map;

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
