/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:29:00 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/07 22:35:08 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	It creates a zombie, name it, and the zombie announces itself. 
*/

void		randomChump(std::string name)
{
	Zombie		newZomb(name);

	newZomb.announce();
}
