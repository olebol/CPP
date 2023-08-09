/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:39:59 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 20:37:22 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course, without the
// angle brackets):
// 			<name> attacks with their <weapon type>

// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP


# include "Weapon.hpp"

class HumanB
{
private:
	std::string			_name;
	Weapon				*_weapon;

	HumanB(void);

public:
	HumanB(const std::string &name);
	HumanB(const HumanB &copy);
	~HumanB(void);

	// Methods
	void		attack(void);
	void		setWeapon(Weapon &weapon);
};

#endif
