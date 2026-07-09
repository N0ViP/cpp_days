#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animals[4];

    Dog dog1, dog2 = dog1;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "----------create animals----------" << std::endl;
    for (int i = 0; i < 2; ++i)
    {
        animals[i] = new Dog();
    }

    for (int i = 2; i < 4; ++i)
    {
        animals[i] = new Cat();
    }

    std::cout << "------------makeSound-------------" << std::endl;

    for (int i = 0; i < 4; ++i)
    {
        animals[i]->makeSound();
    }


    std::cout << "----------delete animals----------" << std::endl;

    for (int i = 0; i < 4; ++i)
    {
        delete animals[i];
    }

    return 0;
}
