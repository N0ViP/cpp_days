#include "phonebook.hpp"

bool GetInput(const std::string& prompt, std::string &input) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
            return false;
        }
        if (!input.empty()) {
            return true;
        }
    }
}

bool AddContact(PhoneBook &phonebook) {
    Contact newContact;
    std::string input;
    if (!GetInput("Enter First Name: ", input)) return false;
    newContact.setFirstName(input);
    if (!GetInput("Enter Last Name: ", input)) return false;
    newContact.setLastName(input);
    if (!GetInput("Enter Nickname: ", input)) return false;
    newContact.setNickname(input);
    if (!GetInput("Enter Phone Number: ", input)) return false;
    newContact.setPhoneNumber(input);
    if (!GetInput("Enter Darkest Secret: ", input)) return false;
    newContact.setDarkestSecret(input);
    phonebook.addContact(newContact);
    return true;
}

bool SearchContacts(PhoneBook &phonebook)
{
    if (!phonebook.searchContacts(phonebook))
        return false;
    return true;
}

int main(void)
{
    PhoneBook phonebook;

    while (true)
    {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (!std::cin)
        {
            std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            std::cout << "Adding a new contact..." << std::endl;
            if (!AddContact(phonebook))
                return 1;
        }
        else if (command == "SEARCH")
        {
            std::cout << "Searching contacts..." << std::endl;
            if (!SearchContacts(phonebook))
                return 1;
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the program." << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}
