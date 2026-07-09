#include "Zombie.hpp"

int main(void)
{
    const int N = 10;
    Zombie* zombies = zombieHorde(N, "YAHYAAAAAAAAAAAAAAAAAAAAAAAA");

    for (int i(0); i < N; i++)
    {
        zombies[i].announce();
    }

    delete[] zombies;
    
}