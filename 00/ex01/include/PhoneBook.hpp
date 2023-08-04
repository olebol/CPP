/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 19:57:53 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/04 15:58:15 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
private:
	Contact		_contacts[8];
	int			_index;

public:
	PhoneBook(void);
	~PhoneBook();

	void	add(void);
	void	search(void);
	void	displayContacts(void);
};

#endif