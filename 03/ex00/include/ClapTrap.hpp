/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 21:43:07 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_maxHitPoints;
		int				_energyPoints;
		int				_attackDamage;

		// Private member functions
		bool		canDoAction(const std::string &action) const;

	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &rhs);
		virtual ~ClapTrap();

		// Member functions
		virtual void		attack(const std::string &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
} ;

#endif
