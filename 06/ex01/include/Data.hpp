/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:11:23 by opelser           #+#    #+#             */
/*   Updated: 2024/01/29 17:27:46 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	private:
		// Private Attributes
		std::string		_name;
		int				_age;

	public:
		// Constructors
		Data();
		Data(const std::string &name, int age);
		Data(const Data &rhs);
		Data &operator=(const Data &rhs);
		~Data();

		// Getters - Setters
		std::string		getName(void) const;
		int				getAge(void) const;
} ;

// Print Overload
std::ostream	&operator<<(std::ostream &o, const Data &rhs);

#endif
