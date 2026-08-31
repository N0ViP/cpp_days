#include "BitcoinExchange.hpp"

#ifndef DB
# define DB "data.csv"
#endif

typedef struct s_date
{
	int year;
	int month;
	int day;
}	t_date;

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
	}

	fill_container(idb_map, idb);
	fill_container(ifile_mp, ifile);

	return 0;
}
