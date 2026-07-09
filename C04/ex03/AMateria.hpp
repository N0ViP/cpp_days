#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const &type = "default");
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();
    
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};