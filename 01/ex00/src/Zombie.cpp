/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:18:18 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/07 22:41:11 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Zombie::Zombie(void)
{ }

Zombie::Zombie(std::string name)
	: _name(name)
{
	std::cout << _name << ": Constructing" << std::endl;
}

Zombie::Zombie(Zombie &copy)
	: _name(copy.getName())
{ }

Zombie::~Zombie()
{
	std::cout << _name << ": Destructing" << std::endl;
}

// ************************************************************************** //
//                                  Getters                                   //
// ************************************************************************** //

std::string		Zombie::getName(void)
{
	return (_name);
}


// ************************************************************************** //
//                                 Functions                                  //
// ************************************************************************** //

void			Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}