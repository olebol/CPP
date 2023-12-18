/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 16:30:01 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

#include <iostream>
#include <string>

int		main(void)
{
	ScavTrap	Scav("ScavTrap Scav");

	std::cout << std::endl;

	Scav.attack("a tree");
	Scav.takeDamage(5);
	Scav.beRepaired(3);
	Scav.guardGate();

	std::cout << std::endl;

	return (0);
}