/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:16:29 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/07 22:39:39 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string		_name;

	public:
		// Constructors
		Zombie(void);
		Zombie(std::string name);
		Zombie(Zombie &copy);
		~Zombie();

		// Functions
		std::string		getName(void);
		void			announce(void);
		
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif