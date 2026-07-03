#include "Base.hpp"

int main()
{

    std::srand(std::time(0));

    Base *b1 = generate();
    std::cout << "identify b1 type by pointer   : ";
    identify(b1);
    std::cout << "identify b1 type by reference : ";
    identify(*b1);

    std::cout << "========================================" << std::endl;

    Base *b2 = generate();
    std::cout << "identify b2 type by pointer   : ";
    identify(b2);
    std::cout << "identify b2 type by reference : ";
    identify(*b2);

    delete b1;
    delete b2;
}
