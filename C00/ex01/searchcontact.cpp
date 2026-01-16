#include "phonebook.hpp"

std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool PhoneBook::searchContacts(PhoneBook &phonebook)
{
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|     Index|First Name| Last Name|Nickname  |" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    for (int i = 0; i < maxContacts && phonebook.contacts[i].getFirstName().empty() == false; ++i)
    {
        std::cout << "|"
                  << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncate(phonebook.contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(phonebook.contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(phonebook.contacts[i].getNickname()) << "|"
                  << std::endl;
    }
    std::cout << " -------------------------------------------" << std::endl;

    std::cout << "Enter the index of the contact to display: ";
    int index;


    if (!(std::cin >> index))
    {
        if (std::cin.eof() == true)
        {
            std::cout << "\nEnd of input detected. Exiting the program." << std::endl;
            return false;
        }
        std::cout << "Invalid input: Please enter a numeric value." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (index < 1 || index > maxContacts || phonebook.contacts[index - 1].getFirstName().empty())
    {
        std::cout << "Error: Contact index out of range or contact is empty." << std::endl;
        return true;
    }

    const Contact &contact = phonebook.contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    return true;
}