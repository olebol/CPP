/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 18:10:31 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public Animal
{
	private:
		Brain		*_brain;

	public:
		// Constructors
		Cat(void);
		Cat(const Cat &copy);
		Cat	&operator=(const Cat &rhs);
		~Cat();

		// Member functions
		void				makeSound(void) const;
		void				setIdea(int index, const std::string &idea);
		const std::string	&getIdea(int index) const;
} ;

#endif
