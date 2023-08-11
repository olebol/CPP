/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:25:01 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:55:03 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <random>
#include <ctime>

#define LEVELAMOUNT	4

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"
#define C_LYELLOW	"\x1b[38;2;255;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //
Harl::Harl(void)
{ }

// ************************************************************************** //
//                                Destructors                                //
// ************************************************************************** //
Harl::~Harl()
{ }

// ************************************************************************** //
//                               Private Methods                              //
// ************************************************************************** //

void		Harl::_debug(void)
{
	const int				quoteAmount = 4;
	const int				random = std::rand() % quoteAmount;
	const std::string		quotes[quoteAmount] = 
	{
		"If anyone needs me, I'll be taking a nap! A-a-and clean this place up or dungeon! Three hours dungeon",
		"I am within my rights!",
		"You try to change my ways? You're poison! You're poison! You need reconditioning! Reconditiooooooooon!",
		"Huh? What? Who's this rigamarole?"
	} ;

	std::cout << C_LGREEN << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::_info(void)
{
	const int				quoteAmount = 3;
	const int				random = std::rand() % quoteAmount;
	const std::string		quotes[quoteAmount] = 
	{
		"Castle Lemongrab has no citizens! You have excess candies! You must donate! Donate!",
		"Blombo, you must heed my instructions! Take off your thiiings!",
		"I can't stands no more!"
	} ;

	std::cout << C_LBLUE << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::_warning(void)
{
	const int				quoteAmount = 4;
	const int				random = std::rand() % quoteAmount;
	const std::string		quotes[quoteAmount] = 
	{
		"This castle is in unacceptable condition! Unacceptable!",
		"Too young! Too young to rule the kingdom!",
		"Stop screaming! Why are you screaming?!",
		"Oh! OOHH! Oh! This sounds awful!!!"
	} ;

	std::cout << C_LYELLOW << C_BOLD << quotes[random] << C_RESET << std::endl;
}

void		Harl::_error(void)
{
	const int				quoteAmount = 3;
	const int				random = std::rand() % quoteAmount;
	const std::string		quotes[quoteAmount] = 
	{
		"Twelve years dungeon. All of you. Dungeon. Seven years, no trials. C'mon, let's move it!",
		"One million years dungeon!",
		"You serve no function. You must be destroyed."
	} ;

	std::cout << C_LRED << C_BOLD << quotes[random] << C_RESET << std::endl;
}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

void		Harl::complain(std::string level)
{
	void	(Harl::*function[LEVELAMOUNT])(void) =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	} ; // Pointers to member functions

	const std::string		levels[LEVELAMOUNT] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	} ; // All complaint levels

	// Checks what complaint level is called
	for (int i = 0; i < LEVELAMOUNT; i++)
	{
		if (level == levels[i])
			(this->*(function[i]))();
	}
}
