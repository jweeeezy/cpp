
//	takes arguments
//	./sedisforlosers <filename> <s1> <s2>
	//	wrong no of arguments
	//	handle bad filename


#include <iostream>

#include <string>

#include <fstream>

int	main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cerr << "Error: bad arguments" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	filename = argv[1];
	std::string string1 = argv[2];
	std::string string2 = argv[3];
	std::string new_filename = filename + ".replace";
	std::ifstream file(filename);

	if (!file)
	{
		std::cerr << "Error: cant open the file" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	line;
	while (getline(filename, line))
	{
		std::cout << line << std::endl;
	}


	file.close();
	return (EXIT_SUCCESS);
}