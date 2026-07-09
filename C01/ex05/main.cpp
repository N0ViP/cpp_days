#include "Harl.hpp"

int main(void)
{
    std::string message;
    std::cout << "enter level: ";
    getline(std::cin, message);
    Harl h;
    h.complain(message);
}