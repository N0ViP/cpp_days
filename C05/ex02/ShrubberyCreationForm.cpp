#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137), target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cls) : AForm(cls), target(cls.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cls)
{
    if (this != &cls)
    {
        AForm::operator=(cls);
        target = cls.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
    {
        throw AForm::GradeTooLowException();
    }
    else if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }
    else
    {
        std::ofstream file((target + "_shrubbery").c_str());
        if (file.is_open())
        {
            file << "                                                         .       " << std::endl;
            file << "                                              .         ;        " << std::endl;
            file << "                 .              .              ;%     ;;         " << std::endl;
            file << "                   ,           ,                :;%  %;          " << std::endl;
            file << "                    :         ;                   :;%;'     .,   " << std::endl;
            file << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl;
            file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
            file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
            file << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
            file << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
            file << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
            file << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl;
            file << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl;
            file << "                        `@%.  `;@%.      ;@@%;                   " << std::endl;
            file << "                          `@%%. `@%%    ;@@%;                    " << std::endl;
            file << "                            ;@%. :@%%  %@@%;                     " << std::endl;
            file << "                              %@bd%%%bd%%:;                      " << std::endl;
            file << "                                #@%%%%%:;;                       " << std::endl;
            file << "                                %@@%%%::;                        " << std::endl;
            file << "                                %@@@%(o);  . '                   " << std::endl;
            file << "                                %@@@o%;:(.,'                     " << std::endl;
            file << "                            `.. %@@@o%::;                        " << std::endl;
            file << "                               `)@@@o%::;                        " << std::endl;
            file << "                                %@@(o)::;                        " << std::endl;
            file << "                               .%@@@@%::;                        " << std::endl;
            file << "                               ;%@@@@%::;.                       " << std::endl;
            file << "                              ;%@@@@%%:;;;.                      " << std::endl;
            file << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
            file.close();
        }
        else
        {
            std::cerr << "Error: Could not create file." << std::endl;
        }
    }
}