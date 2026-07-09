#pragma once

#include <iostream>

class Weapon
{
    std::string type;

public:
    Weapon(void);
    Weapon(std::string t);
    const std::string& getType(void);
    void setType(std::string type);
};
