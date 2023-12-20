/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 19:28:31 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string		_type;

		Animal(const std::string &type);

	public:
		// Constructors
		Animal(void);
		Animal(const Animal &copy);
		Animal	&operator=(const Animal &rhs);
		virtual ~Animal();

		// Getters
		const std::string		&getType(void) const;

		// Member functions
		virtual void			makeSound(void) const;
} ;

#endif
