/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 18:13:11 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

#include <iostream>
#include <string>

int		main(void)
{
	DiamondTrap		Diamond("Diamond");

	std::cout << std::endl;

	Diamond.attack("a tree");
	Diamond.takeDamage(5);
	Diamond.beRepaired(3);
	Diamond.highFiveGuys();
	Diamond.guardGate();
	Diamond.whoAmI();

	std::cout << std::endl;

	return (0);
}