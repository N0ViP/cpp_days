#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    // this->name = "Default_ScavTrap";
    std::cout << "ScavTrap Default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    // this->name = name;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called for " << other.name << std::endl;
}


/*When you pass other to ClapTrap::operator=, you are essentially saying: "Here is my object;
    please just look at the Base part and copy that data."*/

/*The ClapTrap::operator= function will take the FragTrap object you passed (other),
    look only at the ClapTrap slice of that object (name, hit points, etc.),
    and copy those values into the current object's ClapTrap slice.*/

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap Assignment operator called for " << other.name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

