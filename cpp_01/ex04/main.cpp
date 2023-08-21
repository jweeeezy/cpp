
#include <iostream>	// neded for std::cout, std::cerr, std::endl
#include <fstream>	// needed for std::ifstream, std::ofstream
#include <sstream>	// needed for std::stringstream

#define EXPECTED_ARGC 4


static bool	read_and_replace_needle(const std::string& filename,
									const std::string& new_filename,
									const std::string& needle,
									const std::string& replacement)
{
	std::ifstream file_source(filename);
	if (!file_source)
	{
		std::cerr << "Error: cant open the source file" << std::endl;
		return false;
	}

	std::ofstream file_dest(new_filename);
	if (!file_dest)
	{
		std::cerr << "Error: cant open the destination file" << std::endl;
		return false;
	}

	std::string	line_source;

	while (getline(file_source, line_source))
	{
		size_t pos = 0;

		std::stringstream buffer;

		while (true)
		{
			size_t pos_start = pos;
			pos = line_source.find(needle, pos_start);

			if (pos == std::string::npos)
			{
				buffer << line_source.substr(pos_start);
				break ;
			}
			else
			{
				buffer << line_source.substr(pos_start, pos - pos_start) << replacement;
				pos += needle.length();
			}
		}
		file_dest << buffer.str() << std::endl;
	}

	file_source.close();
	file_dest.close();
	return true;
}


static bool	validate_arguments(int argc)
{
	if (argc != EXPECTED_ARGC)
	{
		std::cerr << "Error: bad arguments" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

int	main(int argc, char **argv)
{
	if (validate_arguments(argc) == false)
	{
		return (EXIT_FAILURE);
	}

	std::string	filename = argv[1];
	std::string needle = argv[2];
	std::string replacement = argv[3];
	std::string new_filename = filename + ".replace";

	if (!read_and_replace_needle(filename,
								new_filename,
								needle,
								replacement))
	{
		return (EXIT_FAILURE);
	}


	return (EXIT_SUCCESS);
}

/* ************************************************************************** */