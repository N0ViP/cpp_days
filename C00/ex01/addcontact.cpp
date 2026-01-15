#include "phonebook.hpp"

void PhoneBook::addContact(const Contact &contact)
{
    if (contactCount >= maxContacts)
        contactCount = 0;
    contacts[contactCount++] = contact;
}



