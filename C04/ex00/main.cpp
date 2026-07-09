#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    
    std::cout << "----- Wrong Animals -----" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongMeta->makeSound();


    delete wrongMeta;
    delete wrongCat;
    delete meta;
    delete j;
    delete i;
    return 0;
}
