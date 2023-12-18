/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 21:48:18 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

#include <string>

class Cat : public Animal
{
	private:
		std::string		_type;

	public:
		// Constructors
		Cat(void);
		Cat(const Cat &copy);
		Cat	&operator=(const Cat &rhs);
		~Cat();

		// Member functions
		void			makeSound(void) const;
} ;

#endif
