#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& w): name(n), weapon(w) {}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
