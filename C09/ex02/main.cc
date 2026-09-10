#include <iostream>
#include <sstream>
#include <vector>

template<class U>
void insertElement(U& container, int element)
{
	typename U::size_type	mid = container.size() / 2,
			 				l = 0,
							r = container.size() - 1;

	while (mid < r)
	{
		if (element < container[mid])
		{
			l = mid + 1;
			mid = r;
		}
		else if (element > container[mid])
		{
			r = mid - 1;
			mid = l;
		}
		if (element == container[mid])
		{
			container.insert(mid, element);
			return ;
		}
	}

	container.insert(mid, element);
}

/*
template<class T, class U>
void	sortSecondHalf(T& container, U& res)
{
	typename T::iterator it = container.begin();

	for (; it != container.end(); it++)
	{
		insertElement(res, it->second);
	}
}
*/

template<class T, class U>
void	sortFirstHalf(T& container, U& res)
{
	typename T::iterator it = container.begin();
	res.push_back(it->first);
	it++;

	for (; it != container.end(); it++)
	{
		insertElement(res, it->first);
	}
}

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./PmergeMe \'30 2 34 13\'" << std::endl;
		return 0;
	}

	std::vector< std::pair<int, int> > container;
	std::stringstream ss(av[1]);

	//pars
	bool	firstPair = true;
	int		n;
	std::pair<int, int> tmp;
	while (ss >> n)
	{
		if (n < 0)
		{
			std::cerr << "Error: Invalid args" << std::endl;
			return 1;
		}

		if (firstPair == true)
		{
			tmp.first = n;
		}
		else
		{
			if (tmp.first < n)
			{
				tmp.second = tmp.first;
				tmp.first = n;
			}
			else
			{
				tmp.second = n;
			}
			container.push_back(tmp);
		}

		firstPair = !firstPair;
	}

	//print
	std::vector<std::pair<int,int> >::iterator it = container.begin();
	for (; it != container.end(); it++)
	{
		std::cout << (*it).first << " " << (*it).second << " ";
	}
	std::cout << std::endl;

	//sort
	std::vector<int> res;
	::sortFirstHalf<std::vector<std::pair<int, int> >, std::vector<int> >(container, res);
	//::sortSecondHalf<std::vector<std::pair<int, int> >, std::vector<int> >(container, res);

	//print
	it = container.begin();
	for (; it != container.end(); it++)
	{
		std::cout << (*it).first << " ";
	}
	std::cout << std::endl;

	

}
