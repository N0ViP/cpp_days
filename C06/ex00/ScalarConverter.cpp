#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}



void    ScalarConverter::convert_char(char c)
{
    std::cout << "char: ";
    if (!std::isprint(c))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "'" << c << "'" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarConverter::convert_to_char(long double &res)
{
    std::cout << "char: ";
    if (res >= 0 && res <= 127)
    {
        if (!std::isprint(static_cast<char>(res)))
        {
            std::cout << "Non displayable" << std::endl;
        }
        else
        {
            std::cout << "'" << static_cast<char>(res) << "'" << std::endl;
        }
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }
}

void    ScalarConverter::convert_to_int(long double &res)
{
    std::cout << "int: ";
    if (res <= INT_MAX && res >= INT_MIN)
    {
        std::cout << static_cast<int>(res) << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }
}

void    ScalarConverter::convert_to_float(long double &res, std::string &str)
{
    std::cout << "float: ";
    if (res <= FLT_MAX && res >= -FLT_MAX)
    {
        if (res == std::floor(res))
            std::cout << static_cast<float>(res) << ".0f" << std::endl;
        else
            std::cout << static_cast<float>(res) << "f" << std::endl;
    }
    else if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        std::cout << str << std::endl;
    }
    else if (str == "+inf" || str == "-inf" || str == "nan")
    {
        std::cout << str << "f" << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }
}

void    ScalarConverter::convert_to_double(long double &res, std::string &str)
{
    std::cout << "double: ";
    if (res <= DBL_MAX && res >= -DBL_MAX)
    {
        if (res == std::floor(res))
            std::cout << static_cast<double>(res) << ".0" << std::endl;
        else
            std::cout << static_cast<double>(res) << std::endl;
    }
    else if (str == "+inf" || str == "-inf" || str == "nan")
    {
        std::cout << str << std::endl;
    }
    else if (str == "+inff" || str == "-inff" || str == "nanf")
    {
        str.erase(str.length() - 1, 1);
        std::cout << str << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }
}

void    ScalarConverter::convert_number(long double &res, std::string &str)
{
    convert_to_char(res);
    
    convert_to_int(res);

    convert_to_float(res, str);

    convert_to_double(res, str);

}

void    ScalarConverter::convert(std::string &str)
{
    long double         res;
    std::istringstream  iss(str);


    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        convert_char(str[0]);
        return ;
    }

    iss >> res;
    if (iss.fail())
    {
        res = LDBL_MAX;
    }
    convert_number(res, str);
}
