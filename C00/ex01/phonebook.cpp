#include "phonebook.hpp"

void AddContact(PhoneBook &phonebook)
{
    Contact newContact;
    std::string input;

    do
    {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    newContact.setFirstName(input);

    do
    {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    newContact.setLastName(input);

    do
    {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
    } while (input.empty());
    newContact.setNickname(input);

    do
    {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
    } while (input.empty());
    newContact.setPhoneNumber(input);

    do
    {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    newContact.setDarkestSecret(input);

    phonebook.addContact(newContact);
}

void SearchContacts(PhoneBook &phonebook)
{
    phonebook.searchContacts(phonebook);
}

int main(void)
{
    PhoneBook phonebook;

    while (true)
    {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            std::cout << "Adding a new contact..." << std::endl;
            AddContact(phonebook);
        }
        else if (command == "SEARCH")
        {
            std::cout << "Searching contacts..." << std::endl;
            SearchContacts(phonebook);
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
}
