/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:08:14 by opelser           #+#    #+#             */
/*   Updated: 2024/01/24 16:26:14 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "./AForm.hpp"

class AForm;

class Intern
{
	public:
		// Constructors
		Intern(void);
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &rhs);
		~Intern();

		// Member functions
		AForm		*makeForm(const std::string &formName, const std::string &target);
} ;

#endif
