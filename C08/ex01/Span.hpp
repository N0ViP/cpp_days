#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


class Span
{
	private:
		unsigned int		N;
		std::vector<int>	arr;

	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(const class Span &other);
		Span& operator=(const class Span& other);

		void	addNumber(int NewMember);
		int		shortestSpan();
		int		longestSpan() const;
};
