/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:08 by opelser           #+#    #+#             */
/*   Updated: 2024/01/10 21:06:40 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		// Member functions
		void		createTrees(void) const;
} ;

#endif
