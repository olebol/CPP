/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:25:03 by opelser           #+#    #+#             */
/*   Updated: 2024/02/06 16:30:51 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack> 

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class RPN
{
	private:
		// Constructors and Destructors
		RPN(void);
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		~RPN(void);

	public:
		// Public Methods
		static void		calculate(std::string &input);
		static void		performOperation(std::stack<int> &stack, char op);

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
