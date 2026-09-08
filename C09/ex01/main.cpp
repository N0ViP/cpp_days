#include "RPN.hpp"


int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"1 2 +\"" << std::endl;
		return 0;
	}

	std::stack<int>	st;
	std::stringstream	ss(av[1]);

	if (!parseInput(st, ss))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << st.top() << std::endl;
	return 0;
}
