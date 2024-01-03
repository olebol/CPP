/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2024/01/03 16:56:11 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include "./Form.hpp"

class Bureaucrat
{
	private:
		// Attributes
		std::string		_name;
		int				_grade;

	public:
		// Constructors
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char		*what() const throw();
		} ;
		class GradeTooLowException : public std::exception
		{
			public:
				const char		*what() const throw();
		} ;

		// Getters - Setters
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			setGrade(const int grade);

		// Member functions
		void			promote(void);
		void			demote(void);
		void			signForm(Form &form);
} ;

// Operator overloads
std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
