#include "Span.hpp"


Span::Span(void) : N(0) {}
Span::Span(unsigned int n) : N(n)
{
	arr.reserve(N);
}
Span::~Span() {}
Span::Span(const class Span& other) : N(other.N)
{
	arr = other.arr;
}
Span& Span::operator=(const class Span& other)
{
	if (this != &other)
	{
		N = other.N;
		arr = other.arr;
	}

	return *this;
}

void	Span::addNumber(int NewMember)
{
	if (N < arr.size() + 1)
	{
		throw std::out_of_range("you've reached the max of elements");
	}
	arr.push_back(NewMember);
}

void	Span::addMultiNumbers(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
	if (arr.size() + (e - b) > N)
	{
		throw std::out_of_range("you've reached the max of elements");
	}

	arr.insert(arr.end(), b, e);
}

int		Span::shortestSpan()
{
	if (arr.size() == 0 || arr.size() == 1)
		throw std::range_error("size is small");

	std::sort(arr.begin(), arr.end());
	int a = arr[1] - arr[0];

	for (long unsigned int i = 3; i < arr.size(); i++)
	{
		if (a > arr[i] - arr[i - 1])
		{
			a = arr[i] - arr[i - 1];
		}
	}

	return a;
}

int		Span::longestSpan() const
{
	if (arr.size() == 0 || arr.size() == 1)
		throw std::range_error("size is small");

	return (*std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end()));
}
