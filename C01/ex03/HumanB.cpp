#include "HumanB.hpp"


HumanB::HumanB(std::string n): name(n), weapon(NULL){}

HumanB::HumanB(std::string n, Weapon* w): name(n), weapon(w) {}

void HumanB::setWeapon(Weapon& w) { this->weapon = &w; }

void HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}