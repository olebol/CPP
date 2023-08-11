/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:27:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 21:48:57 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/*
	It creates a zombie, name it, and return it so you can use it outside of 
	the function scope.
*/

Zombie*		newZombie(std::string name)
{
	Zombie		*newZomb = new Zombie(name);

	return (newZomb);
}
