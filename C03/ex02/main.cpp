#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Fraggy");
    frag1.highFivesGuys();

    FragTrap frag2 = frag1;
    frag2.highFivesGuys();

    FragTrap frag3;
    frag3 = frag1;
    frag3.highFivesGuys();

    return 0;
}
