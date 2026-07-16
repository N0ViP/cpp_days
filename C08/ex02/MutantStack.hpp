#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		MutantStack(void);
		MutantStack(const class MutantStack& other);
		MutantStack& operator=(const class MutantStack& other);
		~MutantStack();

		iterator				begin();
		iterator				end();

		reverse_iterator		rbegin();
		reverse_iterator		rend();
};

#include "MutantStack.tpp"
