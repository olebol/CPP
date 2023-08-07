/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:15:50 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/07 22:49:57 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	std::cout << "Calling newZombie: " << std::endl;
	Zombie *Ken = newZombie("Ken");
	std::cout << "Finished newZombie" << std::endl;
	Ken->announce();

	std::cout << "Calling randomChump: " << std::endl;
	randomChump("Brad");
	std::cout << "Finished randomChump" << std::endl;

	delete(Ken);

	std::cout << "\n\n\n";
	std::cout << "As you can see, when we exit the function scope of randomChump, ";
	std::cout << "we cannot access Brad anymore and the object has already been destructed." << std::endl;
	std::cout << "However, since we've allocated Ken on the heap using the <new> keyword, ";
	std::cout << "we can still use him, and he announces himself after the function has been called." << std::endl;

	return (0);
}
