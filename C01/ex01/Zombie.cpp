#include "Zombie.hpp"


Zombie::Zombie(void)
{}

void Zombie::setname(std::string n)
{
    this->name = n;
}

void Zombie::announce( void ) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}