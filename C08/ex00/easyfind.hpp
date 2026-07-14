#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
typename T::iterator	easyfind(T& container, int val)
{
	return (find(container.begin(), container.end(), val));
}
