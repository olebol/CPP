/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:16:29 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 20:45:37 by opelser       ########   odam.nl         */
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
		Zombie(const std::string &name);
		Zombie(const Zombie &copy);
		~Zombie(void);

		// Getters
		std::string		getName(void) const;

		// Methods
		void			announce(void) const;
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif