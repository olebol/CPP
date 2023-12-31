/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:14:39 by opelser           #+#    #+#             */
/*   Updated: 2023/12/20 19:26:34 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string		_type;

		WrongAnimal(const std::string &type);

	public:
		// Constructors
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal	&operator=(const WrongAnimal &rhs);
		~WrongAnimal();

		// Getters
		const std::string		&getType(void) const;

		// Member functions
		void					makeSound(void) const;
} ;

#endif
