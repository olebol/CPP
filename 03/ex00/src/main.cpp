/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/13 17:45:23 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

#include <iostream>
#include <string>

int		main(void)
{
	ClapTrap	Arnold("Arnold");

	// Basic tests
	Arnold.attack("a tree");
	Arnold.takeDamage(5);
	Arnold.beRepaired(3);

	// Edge cases
	Arnold.beRepaired(7);
	Arnold.takeDamage(100);
	Arnold.beRepaired(100);
	

	return (0);
}