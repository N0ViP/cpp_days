#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm *form = NULL;
    AForm *forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i]->getName() == formName)
            form = forms[i];
        else
            delete forms[i];
    }
    if (form)
        std::cout << "Intern creates " << formName << std::endl;
    else
        std::cerr << "Intern cannot create form: " << formName << std::endl;
    return form;
}