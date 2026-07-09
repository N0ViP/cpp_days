#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    std::string name;
    Weapon      &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    void attack(void);
};
