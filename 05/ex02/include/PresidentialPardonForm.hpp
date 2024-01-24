/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:45 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 15:22:27 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		// Attributes
		const std::string		_target;

	public:
		// Constructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		// Member functions
		void		execute(const Bureaucrat &executor) const;
} ;

#endif
