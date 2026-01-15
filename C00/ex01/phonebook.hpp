#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <iomanip>
#include "contact.hpp"


std::string truncate(const std::string &str);

class PhoneBook {
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int contactCount;
public:
    PhoneBook() : contactCount(0){}
    void addContact(const Contact &contact) {
        if (contactCount >= maxContacts)
            contactCount = 0;
        contacts[contactCount++] = contact;
    }
    void searchContacts(PhoneBook &phonebook)
    {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "|     Index|First Name| Last Name|Nickname |" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        for (int i = 0; i < contactCount; ++i) {
            std::cout << "|"
                      << std::setw(10c) << i + 1 << "|"
                      << std::setw(10) << truncate(phonebook.contacts[i].getFirstName()) << "|"
                      << std::setw(10) << truncate(phonebook.contacts[i].getLastName()) << "|"
                      << std::setw(10) << truncate(phonebook.contacts[i].getNickname()) << "|" 
                      << std::endl;
        }
        std::cout << "-------------------------------------------" << std::endl;

        std::cout << "Enter the index of the contact to display: ";
        int index;
        std::cin >> index;
        std::cin.ignore();

        if (index < 1 || index > contactCount) {
            std::cout << "Invalid index." << std::endl;
            return;
        }

        const Contact &contact = phonebook.contacts[index - 1];
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    }
};



#endif