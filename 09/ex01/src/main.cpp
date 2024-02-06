/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 15:51:51 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/RPN.hpp"

int
main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage: " << av[0] << " <string>" << std::endl;
		return (1);
	}

	try
	{
		std::string		input = av[1];
		RPN				rpn;

		rpn.processInput(input);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
