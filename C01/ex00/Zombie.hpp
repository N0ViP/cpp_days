#pragma once

#include <iostream>

class Zombie
{
    std::string name;

public:
    Zombie(std::string n);
    void announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );