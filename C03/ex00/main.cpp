#include "ClapTrap.hpp"

int main() {
    ClapTrap robot1("Alpha");
    ClapTrap robot2;

    robot1.attack("Beta");
    robot2.takeDamage(5);

    robot2.attack("Alpha");
    robot1.takeDamage(3);

    robot1.beRepaired(4);
    robot2.beRepaired(2);

    return 0;
}
