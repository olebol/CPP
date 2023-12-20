/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 19:55:18 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

#include <string>

class Dog : public AbstractAnimal
{
	private:
		Brain		*_brain;

	public:
		// Constructors
		Dog(void);
		Dog(const Dog &copy);
		Dog	&operator=(const Dog &rhs);
		~Dog();

		// Member functions
		void				makeSound(void) const;
		void				setIdea(int index, const std::string &idea);
		const std::string	&getIdea(int index) const;
} ;

#endif
