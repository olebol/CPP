/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:25:01 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 18:05:48 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <random>

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"
# define C_LYELLOW	"\x1b[38;2;255;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

// Constructors
Harl::Harl(void)
{
}


Harl::~Harl()
{
}

// Methods
void		Harl::debug(void)
{
	int			random = std::rand();
	const		std::string		quotes[3] = 
	{
		
	} ;

	std::cout << C_LGREEN << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::info(void)
{
	int			random = std::rand();
	const		std::string		quotes[3] = 
	{
		
	} ;

	std::cout << C_LBLUE << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::warning(void)
{
	int			random = std::rand();
	const		std::string		quotes[3] = 
	{
		
	} ;

	std::cout << C_LBLUE << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::error(void)
{
	int			random = std::rand();
	const		std::string		quotes[3] = 
	{
		
	} ;

	std::cout << C_LRED << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::complain(std::string level)
{
	void	(Harl::*function[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }; // Pointers to member functions
	const std::string		levels[4] = { "debug", "info", "warning", "error" }; // All complain levels

	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			(this->*(function[i]))();
	}
}
