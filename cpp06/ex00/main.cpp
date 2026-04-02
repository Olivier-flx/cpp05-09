#include "ScalarConverter.hpp"

int	main (int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << "you must give an argument\n";
		return (EXIT_FAILURE);
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return (EXIT_SUCCESS);
}
