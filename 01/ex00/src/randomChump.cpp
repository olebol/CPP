/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:29:00 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 21:49:41 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, names it, and then the zombie announces itself. 
*/

void		randomChump(std::string name)
{
	Zombie		newZomb(name);

	newZomb.announce();
}
