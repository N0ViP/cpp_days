#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mystack;

	if (mystack.empty())
	{
		std::cout << "stack is empty\n";
	}
	else
	{
		std::cout << "stack isnt empty\n";
	}

	mystack.push(1337);
	mystack.push(42);
	
	std::stack<int> s(mystack);
	std::cout << s.top() << std::endl;

	std::cout << mystack.top() << std::endl;
	mystack.top() = -1337;
	std::cout << mystack.top() << std::endl;
	mystack.pop();

	if (mystack.empty())
	{
		std::cout << "stack is empty\n";
	}
	else
	{
		std::cout << "stack isnt empty\n";
	}
	
}
