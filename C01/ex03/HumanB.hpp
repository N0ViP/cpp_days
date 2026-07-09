#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    std::string name;
    Weapon      *weapon;

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon* weapon);
    void setWeapon(Weapon& w);
    void attack(void);
};
