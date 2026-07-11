#pragma once



#include <iostream>


template <typename T, typename SIZE, typename FUNC>
void	iter(T* arr, const SIZE size, FUNC func)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = func(arr[i]);
	}

	return ;
}
