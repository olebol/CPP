/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 22:25:18 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <string>

class WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat	&operator=(const WrongCat &rhs);
		~WrongCat();

		// Member functions
		void		makeSound(void) const;
} ;

#endif
