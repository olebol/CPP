/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 14:46:58 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm(void);
		AForm(const std::string &name, const int gradeSign, const int gradeExec);
		AForm(const AForm &copy);
		AForm	&operator=(const AForm &rhs);
		~AForm();

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
		class FormNotSignedException : public std::exception
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
		virtual void	execute(const Bureaucrat &executor) const = 0;
} ;

// Operator overloads
std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
