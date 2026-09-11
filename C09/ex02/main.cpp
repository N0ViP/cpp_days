#include "PmergeMe.hpp"


int main(int ac, char* av[])
{
	std::vector< std::pair<int,int> > container1;
	std::deque< std::pair<int,int> > container2;
	std::vector<int> vec;
	int		n;
	bool	isOdd;


	//print inputs
	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		if (!(ss >> n) || n < 0 || !ss.eof())
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
	for (;j < vec.size(); j++)
	{
		std::cout << vec[j] << " ";
	}
	std::cout << std::endl;

	//first container
	clock_t	start1 = clock();
	isOdd = ::sort(container1, av + 1, ac - 1, n);
	std::vector<std::pair<int, int> > res1;
	if (!container1.empty())
	{
		::sortFirstHalf(container1, res1);
		::sortSecondHalf(res1);
	}
	if (!isOdd)
	{
		insertElement(res1, std::make_pair(n, 0), res1.size());
	}
	clock_t total1 = clock() - start1;


	//second container
	clock_t start2 = clock();
	isOdd = ::sort(container2, av + 1, ac - 1, n);
	std::deque<std::pair<int, int> > res2;
	if (!container2.empty())
	{
		::sortFirstHalf(container2, res2);
		::sortSecondHalf(res2);
	}
	if (!isOdd)
	{
		insertElement(res2, std::make_pair(n, 0), res2.size());
	}
	clock_t total2 = clock() - start2;

	//print result
	std::cout << "After: ";
	std::vector<int>::size_type i = 0;
	for (; i < res1.size(); i++)
	{
		std::cout << res1[i].first << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() 
			<< " elements with std::vector : " <<
			(total1 * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;

	std::cout << "Time to process a range of " << vec.size() 
			<< " elements with std::deque : " 
			<< (total2 * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;
}
