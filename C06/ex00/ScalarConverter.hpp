#include <iostream>
#include <cfloat>
#include <climits>
#include <sstream>
#include <cmath>
#include <cctype>

class ScalarConverter
{
    private:
        static void    convert_char(char c);
        static void    convert_to_char(long double &res);
        static void    convert_to_int(long double &res);
        static void    convert_to_float(long double &res, std::string &str);
        static void    convert_to_double(long double &res, std::string &str);
        static void    convert_number(long double &res, std::string &str);
    public:
        static void    convert(std::string &str);

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();
};
