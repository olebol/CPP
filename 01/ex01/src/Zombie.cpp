/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:18:18 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 21:16:42 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

#define C_LRED		"\x1b[38;2;255;128;128m"
#define C_LBLUE		"\x1b[38;2;128;128;255m"
#define C_LGREEN	"\x1b[38;2;128;255;128m"

#define C_RESET		"\x1b[0m"
#define C_BOLD		"\x1b[1m"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Zombie::Zombie(void)
	: _name()
{
	std::cout << C_BOLD << C_LBLUE << "A generic zombie has risen" << C_RESET << std::endl;
}

Zombie::Zombie(const std::string &name)
	: _name(name)
{
	std::cout << _name << C_BOLD << C_LBLUE << " has risen" <<  C_RESET << std::endl;
}

Zombie::Zombie(const Zombie &copy)
	: _name(copy.getName())
{
	std::cout << _name << C_BOLD << C_LBLUE << " has risen" <<  C_RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name  << C_LRED << C_BOLD << " died... twice?" << C_RESET << std::endl;
}

// ************************************************************************** //
//                                  Getters                                   //
// ************************************************************************** //

std::string		Zombie::getName(void) const
{
	return (_name);
}

// ************************************************************************** //
//                                  Setters                                   //
// ************************************************************************** //

void		Zombie::setName(std::string &name)
{
	_name = name;
}

// ************************************************************************** //
//                                  Methods                                   //
// ************************************************************************** //

void			Zombie::announce(void) const
{
	std::cout << _name << ": " << C_LGREEN << C_BOLD << "BraiiiiiiinnnzzzZ..." << C_RESET << std::endl;
}