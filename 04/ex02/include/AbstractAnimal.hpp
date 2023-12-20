/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 20:00:37 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

#include <string>

class AbstractAnimal
{
	protected:
		std::string		_type;

		AbstractAnimal(const std::string &type);

	public:
		// Constructors
		AbstractAnimal(void);
		AbstractAnimal(const AbstractAnimal &copy);
		AbstractAnimal	&operator=(const AbstractAnimal &rhs);
		virtual ~AbstractAnimal();

		// Getters
		const std::string		&getType(void) const;

		// Member functions
		virtual void			makeSound(void) const = 0;
} ;

#endif
