/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2024/01/03 16:56:11 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		// Attributes
		std::string		_name;
		const int		_requiredGradeSign;
		const int		_requiredGradeExec;
		bool			_signed;

		// Member functions
		void			checkGrade(const int grade) const;

	public:
		// Constructors
		Form(void);
		Form(const std::string &name, const int gradeSign, const int gradeExec);
		Form(const Form &copy);
		Form	&operator=(const Form &rhs);
		~Form();

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
		int				getRequiredGradeSign(void) const;
		int				getRequiredGradeExec(void) const;
		bool			getSigned(void) const;

		// Member functions
		void			beSigned(const Bureaucrat &bureaucrat);
} ;

// Operator overloads
std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
