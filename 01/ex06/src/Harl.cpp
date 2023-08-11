/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 17:25:01 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 20:39:40 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
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
	: _filter(insignificant)
{ }

Harl::Harl(const std::string &initFilter)
{
	setFilter(initFilter);
}

// ************************************************************************** //
//                                 Destructors                                //
// ************************************************************************** //
Harl::~Harl()
{ }

// ************************************************************************** //
//                                   Setters                                  //
// ************************************************************************** //

void			Harl::setFilter(const std::string &filterString)
{
	const std::string		levels[LEVELAMOUNT] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	} ; // All complaint levels

	for (int i = 0; i < LEVELAMOUNT; i++)
	{
		if (filterString == levels[i])
		{
			this->_filter = (eLevel) i;
			return ;
		}
	}
	_filter = insignificant;
}

// ************************************************************************** //
//                                   Getters                                  //
// ************************************************************************** //

eLevel		Harl::getFilter(void) const
{
	return (this->_filter);
}

// ************************************************************************** //
//                               Private Methods                              //
// ************************************************************************** //

void		Harl::_debug(void)
{
	int			random = std::rand() % 4;
	const		std::string		quotes[4] = 
	{
		"If anyone needs me, I'll be taking a nap! A-a-and clean this place up or dungeon! Three hours dungeon\n",
		"I am within my rights!\n",
		"You try to change my ways? You're poison! You're poison! You need reconditioning! Reconditiooooooooon!\n",
		"Huh? What? Who's this rigamarole?\n"
	} ;

	std::cout << C_LGREEN << C_BOLD << "[ DEBUG ]\n" << quotes[random] << C_RESET << std::endl;
}

void		Harl::_info(void)
{
	int			random = std::rand() % 3;
	const		std::string		quotes[3] = 
	{
		"Castle Lemongrab has no citizens! You have excess candies! You must donate! Donate!\n",
		"Blombo, you must heed my instructions! Take off your thiiings!\n",
		"I can't stands no more!\n"
	} ;

	std::cout << C_LBLUE << C_BOLD << "[ INFO ]\n" << quotes[random] << C_RESET << std::endl;
}

void		Harl::_warning(void)
{
	int			random = std::rand() % 4;
	const		std::string		quotes[4] = 
	{
		"This castle is in unacceptable condition! Unacceptable!\n",
		"Too young! Too young to rule the kingdom!\n",
		"Stop screaming! Why are you screaming?!\n",
		"Oh! OOHH! Oh! This sounds awful!!!\n"
	} ;

	std::cout << C_LYELLOW << C_BOLD << "[ WARNING ]\n" << quotes[random] << C_RESET << std::endl;
}

void		Harl::_error(void)
{
	int			random = std::rand() % 3;
	const		std::string		quotes[3] = 
	{
		"Twelve years dungeon. All of you. Dungeon. Seven years, no trials. C'mon, let's move it!\n",
		"One million years dungeon!\n",
		"You serve no function. You must be destroyed.\n"
	} ;

	std::cout << C_LRED << C_BOLD << "[ ERROR ]\n" << quotes[random] << C_RESET << std::endl;
}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

eLevel		whatExecute(const Harl &harl, const std::string &level)
{
	const std::string		levels[LEVELAMOUNT] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	} ; // All complaint levels

	for (int i = 0; i < insignificant; i++)
	{
		if (i >= harl.getFilter() && level == levels[i])
			return ((eLevel) i);
	}
	return (insignificant);
}

void		Harl::complain(const std::string &level)
{
	void	(Harl::*complainFunction[LEVELAMOUNT])(void) =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	} ; // Pointers to member functions

	// Generates a random seed for the rand() function, which gets used to select a random quote
	std::srand((unsigned int) std::time(nullptr));

	// Checks what complaint level is called and applies the filter
	switch (whatExecute(*this, level))
	{
		case debug:
			if (debug >= getFilter())
				(this->*complainFunction[debug])();
			break ;

		case info:
			if (info >= getFilter())
				(this->*complainFunction[info])();
			break ;

		case warning:
			if (warning >= getFilter())
				(this->*complainFunction[warning])();
			break ;
	
		case error:
			if (error >= getFilter())
				(this->*complainFunction[error])();
			break ;

		default :
			std::cout << "[ Probably complaining about Princess Bubblegum... ]" << std::endl;
			break ;
	}
}