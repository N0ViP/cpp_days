
template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const class MutantStack& other) : std::stack<T>(other) {}
{
	
}


