#include "MutantStack.hpp"


int main()
{
    MutantStack<int> mstack;

    mstack.push(1337);
    mstack.push(-1337);
    mstack.push(42);
    mstack.push(-42);
    
    mstack.pop();

    std::cout << "top element: " << mstack.top() << std::endl;

    if (mstack.empty())
    {
        std::cout << "stack is empty" << std::endl;
    }
    else
    {
        std::cout << "stack is not empty" << std::endl;
    }

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "stack elements: ";
    for (; it != ite; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> mstack2(mstack);
    MutantStack<int> mstack3;
    if (mstack3.empty())
    {
        std::cout << "stack 3 is empty" << std::endl;
    }
    else
    {
        std::cout << "stack 3 is not empty" << std::endl;
    }

    mstack3 = mstack2;
    if (mstack3.empty())
    {
        std::cout << "stack 3 is empty" << std::endl;
    }
    else
    {
        std::cout << "stack 3 is not empty" << std::endl;
    }

    mstack3.push(21);
    mstack3.push(-21);
    
    MutantStack<int>::reverse_iterator rit = mstack3.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack3.rend();

    std::cout << "stack 3 elements in reverse order: ";
    for (; rit != rite; ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}