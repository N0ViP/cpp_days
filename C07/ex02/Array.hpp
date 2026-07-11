#pragma once


#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		unsigned int	s;
		T*				arr;

	public:
		Array(void) : arr(NULL), s(0) {}
		Array(unsigned int n) : s(n)
		{
			arr = new T[n];
		}
		Array(const class Array& other) : s(other.size())
		{
			arr = new T[s];
			for (unsigned int i = 0; i < s; i++)
			{
				arr[i] = other.arr[i];
			}
		}
		Array& operator=(const class Array& other)
		{
			if (this != &other)
			{
				delete[] arr;
				s = other.size();
				arr = new T[s];
				for (unsigned int i = 0; i < s; i++)
				{
					arr[i] = other.arr[i];
				}
			}

			return *this;
		}
		~Array() { delete[] arr; }

		T&	operator[](unsigned int i)
		{
			if (i >= s)
				throw std::out_of_range("Index out of range");
			return arr[i];
		}

		const T&	operator[](unsigned int i) const
		{
			if (i >= s)
				throw std::out_of_range("Index out of range");
			return arr[i];
		}

		unsigned int	size(void) const { return s; }
		
};
