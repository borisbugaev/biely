#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <cstring>
#include <string_view>
#include <chrono>

// define expected assertions for main()
const int EXP_ARGC{4};
const std::string EXP_ARGSV[EXP_ARGC] = {"SELF", "INPUT FILE 1", "INPUT FILE 2", "OUTPUT FILE"};
const std::string ARG_TYPE{"ENTER NAME OF"};

int main(int argc, char** argv)
{
    // get input arguments
    // if runtime assertions != expected assertions, prompt user inline
    std::string input_arg[EXP_ARGC];
    input_arg[0] = argv[0];
    if (argc != EXP_ARGC)
    {
        for (int i = 1; i < EXP_ARGC; i++)
        {
            std::cout << ARG_TYPE << " " << EXP_ARGSV[i] << ": ";
            std::cin >> input_arg[i];
        }
    }
    else
    {
        for (int i = 1; i < EXP_ARGC; i++)
        {
            input_arg[i] = argv[i];
        }
    }

    // load files at provided names
    std::ifstream in_file_1(input_arg[1]);
	if (!in_file_1.is_open())
	{
        std::cerr << "Error opening first input file." << std::endl;
        std::cerr << strerror(errno) << std::endl;
    }
    std::ifstream in_file_2(input_arg[2]);
	if (!in_file_2.is_open())
	{
        std::cerr << "Error opening second input file." << std::endl;
        std::cerr << strerror(errno) << std::endl;
    }
	std::ofstream out_file(input_arg[3]);
    if (!out_file.is_open())
	{
        std::cerr << "Error opening output file." << std::endl;
        std::cerr << strerror(errno) << std::endl;
    }
	std::string line{};
	while (std::getline(file, line))
	{
		std::string_view candidate{line};
		if (1)
		{
			std::cout << "Never replaced the placeholder";
		}
	}
	in_file_1.close();
    in_file_2.close();
	out_file.close();
    return 0;
}