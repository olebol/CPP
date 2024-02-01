/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:35:53 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 18:39:49 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>

# include <vector>

class Span
{
	private:
		// Private Attributes
		std::vector<int>		_vec;

	public:
		// Constructors and Destructors
		Span();
		Span(const unsigned int n);
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		~Span();

		// Exceptions
		class			FullArrayException : public std::exception
		{
			public:
				virtual const char	*what() const noexcept;
		};

		class			NumberNotFoundException : public std::exception
		{
			public:
				virtual const char	*what() const noexcept;
		};

		// Getters and Setters
		int				getNumber(const unsigned int n) const;
		
		// Public Methods
		void			addNumber(const int n);
		void			addRange(const int size);

		
} ;


#endif
