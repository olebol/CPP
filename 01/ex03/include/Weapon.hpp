/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:27:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 19:29:44 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Implement a Weapon class that has:
// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as parameter.

#ifndef WEAPON_HPP
# define WEAPON_HPP


#include <string>

class Weapon
{
private:
	std::string		_type;

public:
	Weapon(void);
	Weapon(const std::string &type);
	Weapon(const Weapon &copy);
	~Weapon(void);

	// Getters
	const std::string		&getType(void) const;

	// Setters
	void					setType(const std::string &type);
};

#endif
