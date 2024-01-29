/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:06:51 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 17:14:27 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

# include "Data.hpp"

class Serializer
{
	private:
		// Constructors
		Serializer();
		Serializer(const Serializer &rhs);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();

	public:
		// Public Methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
} ;


#endif
