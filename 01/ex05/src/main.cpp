/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:26:40 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:51:25 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int		main(void)
{
	Harl		lemongrab;

	// Generates a random seed for the rand() function, which gets used to select a random quote
	std::srand((unsigned int) (std::time(nullptr)));

	lemongrab.complain("DEBUG");
	lemongrab.complain("INFO");
	lemongrab.complain("WARNING");
	lemongrab.complain("ERROR");
	return (0);
}