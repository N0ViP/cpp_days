#include "PmergeMe.hpp"


int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector< std::pair<int,int> > container1;
	std::deque< std::pair<int,int> > container2;
	std::stringstream ss(av[1]), ss1(av[1]), ss2(av[1]);
	std::vector<int> vec;
	int		n;
	bool	firstPair;


	//print inputs
	while (ss2 >> n)
	{
		if (n < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(n);
	}
	if (vec.empty())
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int>::size_type j = 0;
	std::cout << "Before: ";
	for (; j < 5 && j < vec.size(); j++)
	{
		std::cout << vec[j] << " ";
	}
	if (5 < vec.size())
		std::cout << "[...]";
	std::cout << std::endl;

	//first container
	clock_t	start1 = clock();
	firstPair = ::sort(container1, ss, n);
	std::vector<std::pair<int, int> > res1;
	if (!container1.empty())
	{
		::sortFirstHalf(container1, res1);
		::sortSecondHalf(res1);
	}
	if (!firstPair)
	{
		insertElement(res1, std::make_pair(n, 0), res1.size());
	}
	clock_t total1 = clock() - start1;


	//second container
	clock_t start2 = clock();
	firstPair = ::sort(container2, ss1, n);
	std::deque<std::pair<int, int> > res2;
	if (!container2.empty())
	{
		::sortFirstHalf(container2, res2);
		::sortSecondHalf(res2);
	}
	if (!firstPair)
	{
		insertElement(res2, std::make_pair(n, 0), res2.size());
	}
	clock_t total2 = clock() - start2;

	//print result
	std::cout << "After: ";
	std::vector<int>::size_type i = 0;
	for (; i < 5 && i < res1.size(); i++)
	{
		std::cout << res1[i].first << " ";
	}
	if (5 < res1.size())
		std::cout << "[...]";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() 
			<< " elements with std::vector : " <<
			(total1 * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;

	std::cout << "Time to process a range of " << vec.size() 
			<< " elements with std::deque : " 
			<< (total2 * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;
}
