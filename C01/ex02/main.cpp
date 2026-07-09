#include <iostream>

int main(void)
{
    std::string str("HI THIS IS BRAIN");

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << &str << " : The memory address of the string variable." << std::endl;
    std::cout << stringPTR << " : The memory address held by stringPTR." << std::endl;
    std::cout << &stringREF << " : The memory address held by stringREF." << std::endl;
    std::cout << "               ------------------" << std::endl;
    std::cout << str << " : The value of the string variable." << std::endl;
    std::cout << *stringPTR << " : The value pointed to by stringPTR." << std::endl;
    std::cout << stringREF << " : The value pointed to by stringREF." << std::endl;

    
}