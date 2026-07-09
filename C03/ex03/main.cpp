#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap dt1("Dia");
    dt1.whoAmI();
    dt1.attack("TargetA");
    dt1.takeDamage(30);
    dt1.beRepaired(20);
    dt1.guardGate();
    dt1.highFivesGuys();

    std::cout << "------------------------" << std::endl;
    DiamondTrap dt2 = dt1;
    dt2.whoAmI();
    std::cout << "------------------------" << std::endl;

    DiamondTrap dt3;
    dt3 = dt1;
    dt3.whoAmI();

    return 0;
}
