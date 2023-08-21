
#include <iostream>	// neded for std::cout, std::cerr, std::endl
#include <fstream>	// needed for std::ifstream, std::ofstream
#include <sstream>	// needed for std::stringstream
#include <cstdlib>	// needed for linux, MACROS

#define EXPECTED_ARGC 4

static bool	validate_arguments(int argc, char **argv)
{
	if (argc != EXPECTED_ARGC)
	{
		std::cerr << "Error: bad arguments!" << std::endl;
		return false;
	}
	for (int i = 0; i < argc; ++i)
	{
		std::string	arg = argv[i];
		if (arg.empty() == true)
		{
			std::cerr << "Error: no empty arguments allowed!" << std::endl;
			return false;
		}
	}
	return true;
}

static bool copy_and_replace(	std::ifstream& file_source,
								std::ofstream& file_dest,
								const std::string& needle,
								const std::string& replacement)
{
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
				buffer	<< line_source.substr(pos_start, pos - pos_start)
						<< replacement;
				pos += needle.length();
			}
		}
		file_dest << buffer.str() << std::endl;
	}
	return true;
}

static bool	prepare_files_and_replace_needle(	const std::string& filename,
												const std::string& new_filename,
												const std::string& needle,
												const std::string& replacement)
{
	std::ifstream file_source(filename.c_str());	// c11 --> std::string
	if (!file_source)
	{
		std::cerr << "Error: cant open the source file!" << std::endl;
		return false;
	}

	std::ofstream file_dest(new_filename.c_str());	// c11 --> std::string
	if (!file_dest)
	{
		std::cerr << "Error: cant open the destination file!" << std::endl;
		return false;
	}

	if (copy_and_replace(file_source, file_dest, needle, replacement) == false)
	{
		return false;
	}

	return true;
}

int	main(int argc, char **argv)
{
	if (validate_arguments(argc, argv) == false)
	{
		return (EXIT_FAILURE);
	}

	std::string	filename = argv[1];
	std::string needle = argv[2];
	std::string replacement = argv[3];
	std::string new_filename = filename + ".replace";

	if (prepare_files_and_replace_needle(	filename,
											new_filename,
											needle,
											replacement) == false)
	{
		return (EXIT_FAILURE);
	}

	std::cout	<< "\nFile has been processed successfully.\n"
				<< std::endl;

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
