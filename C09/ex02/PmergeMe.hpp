#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>


std::vector<std::size_t> fordJohnsonOrder(std::size_t size);

template<class U>
void insertElement(U& container, int element, typename U::size_type r)
{
	typename U::size_type	mid, l = 0;

	while (l < r)
	{
		mid = l + (r - l) / 2;

		if (element > container[mid])
			l = mid + 1;
		else
			r = mid;
	}

	container.insert(container.begin() + l , element);
}

template<class T, class U>
void	sortSecondHalf(T& container, U& res)
{
	std::vector<std::size_t> order = fordJohnsonOrder(container.size());
	insertElement(res, container[0].second, res.size());


	for (std::size_t i = 0; i < order.size(); i++)
	{
		insertElement(res, container[order[i]].second, order[i] + 1);
	}
}


template<class T, class U>
void	sortFirstHalf(T& container, U& res)
{
	std::vector<std::size_t> order = fordJohnsonOrder(container.size());

	res.push_back(container[0].first);

	for (std::size_t i = 0; i < order.size(); i++)
	{
		insertElement(res, container[order[i]].first, res.size());
	}
}

template <class T>
bool	sort(T& container, std::stringstream& ss, int& n)
{
	std::pair<int, int> tmp;
	bool	firstPair = true;

	while (ss >> n)
	{
		if (firstPair == true)
		{
			tmp.first = n;
		}
		else
		{
			if (tmp.first < n)
			{
				tmp.second = tmp.first;
				tmp.first = n;
			}
			else
			{
				tmp.second = n;
			}
			container.push_back(tmp);
		}

		firstPair = !firstPair;
	}
	return firstPair;
}
