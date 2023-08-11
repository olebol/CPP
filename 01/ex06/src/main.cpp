/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:26:40 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:51:49 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Harl.hpp"

int		main(int ac, char **av)
{
	try
	{

		if (ac != 2)
			throw (std::invalid_argument("Incorrect use:\n ./harlFilter [level]"));

		// Generates a random seed for the rand() function, which gets used to select a random quote
		std::srand((unsigned int) (std::time(nullptr)));

		Harl		lemongrab(av[1]);

		lemongrab.complain("DEBUG");
		lemongrab.complain("INFO");
		lemongrab.complain("WARNING");
		lemongrab.complain("ERROR");
	}
	catch (const std::exception &err)
	{
		std::cerr << C_LRED << C_BOLD << err.what() << C_RESET << std::endl;
		return (1);
	}

	return (0);
}