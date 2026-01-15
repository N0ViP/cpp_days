#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <iomanip>
#include <limits>
#include "contact.hpp"


class PhoneBook {
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int contactCount;
public:
    PhoneBook() : contactCount(0) {}
    void addContact(const Contact &contact);
    void searchContacts(PhoneBook &phonebook);

};


#endif