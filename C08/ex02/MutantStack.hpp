#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:
		

	public:
		MutantStack(void);
		MutantStack(const class MutantStack& other);
		MutantStack& operator=(const class MutantStack& other);
		~MutantStack();

		container_type::iterator		begin();
		container_type::iterator		end();
		container_type::const_iterator	cbegin();
		container_type::const_iterator	cend();

		container_type::reverse_iterator		rbegine();
		container_type::reverse_iterator		rend();
		container_type::const_reverse_iterator	crbegine();
		container_type::const_reverse_iterator	crend();
};

#include "MutantStack.tpp"
