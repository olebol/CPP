/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:25:01 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 18:36:24 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <random>
#include <ctime>

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
	int			random = std::rand() % 4;
	const		std::string		quotes[4] = 
	{
		"If anyone needs me, I'll be taking a nap! A-a-and clean this place up or dungeon! Three hours dungeon",
		"I am within my rights!",
		"You try to change my ways? You're poison! You're poison! You need reconditioning! Reconditiooooooooon!",
		"Huh? What? Who's this rigamarole?"
	} ;

	std::cout << C_LGREEN << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::info(void)
{
	int			random = std::rand() % 3;
	const		std::string		quotes[3] = 
	{
		"Castle Lemongrab has no citizens! You have excess candies! You must donate! Donate!",
		"Blombo, you must heed my instructions! Take off your thiiings!",
		"I can't stands no more!"
	} ;

	std::cout << C_LBLUE << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::warning(void)
{
	int			random = std::rand() % 3;
	const		std::string		quotes[3] = 
	{
		"Too young! Too young to rule the kingdom!",
		"Stop screaming! Why are you screaming?!",
		"Oh! OOHH! Oh! This sounds awful!!!"
	} ;

	std::cout << C_LYELLOW << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::error(void)
{
	int			random = std::rand() % 4;
	const		std::string		quotes[4] = 
	{
		"This castle is in unacceptable condition! Unacceptable!",
		"Twelve years dungeon. All of you. Dungeon. Seven years, no trials. C'mon, let's move it!",
		"One million years dungeon!",
		"You serve no function. You must be destroyed."
	} ;

	std::cout << C_LRED << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::complain(std::string level)
{
	void	(Harl::*function[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	} ; // Pointers to member functions

	const std::string		levels[4] =
	{
		"debug",
		"info",
		"warning",
		"error"
	} ; // All complaint levels

	// Generates a random seed for the rand() function, which gets used to select a random quote
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Checks what complaint level is called
	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(level) == 0)
			(this->*(function[i]))();
	}
}
