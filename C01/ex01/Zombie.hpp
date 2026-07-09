#pragma once

#include <iostream>

class Zombie
{
    std::string name;

public:
    Zombie(void);
    void setname(std::string n);
    void announce( void ) const;
};

Zombie* zombieHorde( int N, std::string name );