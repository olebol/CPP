/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:16:29 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/08 21:40:54 by opelser       ########   odam.nl         */
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
		Zombie(std::string &name);
		Zombie(Zombie &copy);
		~Zombie(void);

		// Functions
		std::string		getName(void);
		void			announce(void);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif