/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 18:05:50 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Constructors
		ScavTrap(void);
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap	&operator=(const ScavTrap &rhs);
		~ScavTrap();

		// Member functions
		virtual void		attack(const std::string &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
		void				guardGate(void);
} ;

#endif
