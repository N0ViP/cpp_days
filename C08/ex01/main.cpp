#include "Span.hpp"
#include <ctime>
#include <cstdlib>
/*
#define MAX_VAL	10000

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Span				arr(MAX_VAL);



	return 0;
}*/



int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
