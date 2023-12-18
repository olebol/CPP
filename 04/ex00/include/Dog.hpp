/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 20:29:12 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

#include <string>

class Dog : public Animal
{
	protected:
		std::string		_type;

	public:
		// Constructors
		Dog(void);
		Dog(const Dog &copy);
		Dog	&operator=(const Dog &rhs);
		~Dog();

		// Member functions
		void		makeSound(void) const;
} ;

#endif
