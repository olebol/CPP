/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:44:51 by opelser           #+#    #+#             */
/*   Updated: 2023/12/18 23:57:17 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string			_ideas[100];

	public:
		// Constructors
		Brain(void);
		Brain(const Brain &copy);
		Brain	&operator=(const Brain &rhs);

		// Destructors
		~Brain(void);

		// Setters
		void				setIdea(int index, const std::string &idea);

		// Getters
		const std::string	&getIdea(int index) const;
} ;

#endif