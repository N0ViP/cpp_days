#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_FragTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    // this->name = "Default_FragTrap";
    std::cout << "FragTrap Default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    // this->name = name;
    std::cout << "FragTrap  constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Copy assignment operator called for " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}

