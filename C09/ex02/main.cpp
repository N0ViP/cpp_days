#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	std::vector< std::pair<int,int> > container1, res1;
	std::deque< std::pair<int,int> > container2, res2;
	std::vector<int> vec;
	int		n;

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
	implement(container1, res1, av + 1, ac -1);
	clock_t total1 = clock() - start1;


	//second container
	clock_t start2 = clock();
	implement(container2, res2, av + 1, ac - 1);
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
