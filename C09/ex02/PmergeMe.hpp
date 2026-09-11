#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>


std::vector<std::size_t> fordJohnsonOrder(std::size_t size);
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b);

template<class U>
void insertElement(U& container, std::pair<int, int> element, typename U::size_type r)
{
	typename U::size_type	mid, l = 0;

	while (l < r)
	{
		mid = l + (r - l) / 2;

		if (compare(container[mid], element))
			l = mid + 1;
		else
			r = mid;
	}

	container.insert(container.begin() + l , element);
}

template<class U>
void	sortSecondHalf(U& res)
{
	U	pending = res;
	std::vector<std::size_t> order = fordJohnsonOrder(pending.size());
	res.insert(res.begin(), std::make_pair(pending[0].second, 0));
	
	for (std::size_t i = 0; i < order.size(); i++)
	{
		insertElement(res, std::make_pair(pending[order[i]].second, 0), order[i] + i + 1);
	}
}


template<class T, class U>
void	sortFirstHalf(T& container, U& res)
{
	std::vector<std::size_t> order = fordJohnsonOrder(container.size());
	res.insert(res.begin(), container[0]);

	for (std::size_t i = 0; i < order.size(); i++)
	{
		insertElement(res, container[order[i]], res.size());
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
