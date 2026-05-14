#pragma once

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& cls);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cls);
        ~ShrubberyCreationForm();

        virtual void execute(const Bureaucrat& executor) const;

};