
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        materiaList[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.materiaList[i])
            materiaList[i] = other.materiaList[i]->clone();
        else
            materiaList[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materiaList[i];
            if (other.materiaList[i])
                materiaList[i] = other.materiaList[i]->clone();
            else
                materiaList[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        delete materiaList[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (materiaList[i] == NULL)
        {
            materiaList[i] = m;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materiaList[i] && materiaList[i]->getType() == type)
        {
            return materiaList[i]->clone();
        }
    }
    return NULL;
}
