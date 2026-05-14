#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
        std::string	target;

        
        public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& cls);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& cls);
        ~PresidentialPardonForm();
        
        void execute(const Bureaucrat& executor) const;
};