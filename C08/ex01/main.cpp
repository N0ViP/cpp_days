#include "Span.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_SIZE	10000

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Span				arr(MAX_SIZE);
	std::vector<int>	vec(MAX_SIZE - 1);


	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		vec[i] = rand() % 10000000;
	}
	arr.addMultiNumbers(vec.begin(), vec.end());
	try
	{
		arr.addNumber(-1337);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		arr.addNumber(-1337);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "shorest span : " << arr.shortestSpan() << std::endl;
	std::cout << "longest span : " << arr.longestSpan() << std::endl;

	return 0;
}

