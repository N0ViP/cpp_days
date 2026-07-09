#include "Zombie.hpp"

int main(void)
{
    randomChump("Stack");
    Zombie *zombie = newZombie("Heap");
    zombie->announce();
    delete zombie;
}