/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:33:01 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 20:07:20 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>

template <typename T>
class Array
{
	private:
		// Private Attributes
		unsigned int		_size;
		T					*_array;

	public:
		// Constructors
		Array();
		Array(const unsigned int n);
		Array(const Array &rhs);
		Array &operator=(const Array &rhs);
		~Array();

		// Operator Overload
		T		&operator[](const unsigned int i) const;

		// Public Methods
		unsigned int	size(void) const;
} ;

# include "./Array.tpp"

#endif
