/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:15:50 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 21:53:36 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int		main(void)
{
	int			hordeSize = 5;
	Zombie		*horde = ZombieHorde(hordeSize, "Brad");

	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete [] horde;

	return (0);
}
