/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillert <jwillert@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:43:17 by jwillert          #+#    #+#             */
/*   Updated: 2023/08/18 12:32:34 by jwillert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// needed for std::cout and std::endl

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(size_t i = 1; i < (size_t) argc; ++i)
	{
		std::string	str;

		str = argv[i];
		for (std::string::iterator str_it = str.begin();
			str_it != str.end();
			++str_it)
		{
			std::cout << static_cast<char> (std::toupper(static_cast<unsigned char>(*str_it)));
		}
	}
	std::cout << std::endl;
    return (0);
}