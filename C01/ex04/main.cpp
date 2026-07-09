#include <iostream>
#include <fstream>

void read_hole_file(std::string &str, std::ifstream &file)
{
    std::string line;
    bool first_nl = false;

    while (getline(file, line))
    {
        if (first_nl)
            str += '\n';
        str += line;
        first_nl = true;
    }
}

void replace(std::string &result, std::string &str, std::string s1, std::string s2)
{
    size_t found_pos = 0;
    size_t curr_pos = 0;

    if (s1.empty())
    {
        result = str;
        return;
    }

    while ((found_pos = str.find(s1, curr_pos)) != std::string::npos)
    {
        result += str.substr(curr_pos, found_pos - curr_pos);
        result += s2;
        curr_pos = found_pos + s1.size();
    }
    result += str.substr(curr_pos);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./Sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream file(av[1]);
    if (file.is_open() == false)
    {
        std::cerr << "Failed to open " << av[1] << std::endl;
        return 1;
    }

    std::string str;
    read_hole_file(str, file);
    file.close();

    std::string result;
    replace(result, str, av[2], av[3]);

    std::string file_output_name = static_cast<std::string>(av[1]) + ".replace";
    std::ofstream file_output(file_output_name.c_str());
    if (file_output.is_open() == false)
    {
        std::cerr << "Failed to open " << file_output_name << std::endl;
        return 1;
    }

    file_output << result;
    file_output.close();
}
