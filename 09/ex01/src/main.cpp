/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 16:32:47 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/RPN.hpp"

int
main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << RED << "Usage: " << av[0] << " <string>"  << RESET << std::endl;
		return (1);
	}

	try
	{
		std::string		input = av[1];

		RPN::calculate(input);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
