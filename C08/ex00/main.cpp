#include "easyfind.hpp"

void	check(std::vector<int>::iterator& it, std::vector<int>::iterator end)
{
	if (it == end)
	{
		std::cout << "emelent not found" << std::endl;
	}
	else
	{
		std::cout << "element found : " << *it << std::endl;
	}

	return ;
}

int main()
{
	std::vector<int> vec(10);

	for (int i = 1; i < 10; i++)
	{
		vec[i] = i;
	}

	std::vector<int>::iterator it = easyfind(vec, 9);
	check(it, vec.end());

	it = easyfind(vec, 99);
	check(it, vec.end());
	

}
