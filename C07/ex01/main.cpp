#include "iter.hpp"

int	factor(int &var)
{
	return (var *= 10);
}

int	upper(char &var)
{
	if (var >= 'a' && var <= 'z')
	{
		var -= 32;
	}
	return (var);
	
}

int main()
{
	const int arr_size = 10;
	int arr[arr_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter<int, int, int(*)(int&)>(arr, arr_size, factor);

	for (int i = 0; i < arr_size; i++)
	{
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	
	std::cout << "============================" << std::endl;

	const int word_size = 7;
	char word[word_size] = {'H', 'e', 'l', 'l', 'o', '!'};


	std::cout << "before: " << word << std::endl;

	iter<char, int, int(*)(char&)>(word, word_size, upper);

	std::cout << "after: " << word << std::endl;

}
