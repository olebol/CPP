/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ZombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/08 21:22:48 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 21:53:12 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie		*ZombieHorde(int N, std::string name)
{
	Zombie		*horde = new Zombie [N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}
