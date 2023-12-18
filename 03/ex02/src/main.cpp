/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 19:34:42 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"

#include <iostream>
#include <string>

int		main(void)
{
	FragTrap	Frag("Frag");

	std::cout << std::endl;

	Frag.attack("a tree");
	Frag.takeDamage(5);
	Frag.beRepaired(3);
	Frag.highFiveGuys();

	std::cout << std::endl;

	return (0);
}