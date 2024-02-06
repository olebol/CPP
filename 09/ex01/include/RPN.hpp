/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:25:03 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 17:07:04 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack> 

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

namespace RPN
{
		// Function prototypes

		// Calculate the result of the input string formatted in the Reverse Polish Notation
		void		calculate(std::string &input);

		// Exceptions
		class EmptyStackException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Stack is empty");
				}
		};

		class NotEnoughValuesException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Not enough values in stack");
				}
		};

		class InvalidValueException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid value");
				}
		};

		class InvalidOperationException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid operation");
				}
		};

		class CalculationNotPossible : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Calculation not possible");
				}
		};
} ;


#endif
