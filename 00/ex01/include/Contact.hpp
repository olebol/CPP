/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 21:27:13 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 21:10:21 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


# include <string>
# include <iostream>

class Contact
{
	private:
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkestSecret;

	public:
		// Constructors
		Contact(void);
		Contact(const std::string &firstName, const std::string &lastName, \
				const std::string &nickname, const std::string &phoneNumber, \
				const std::string &darkestSecret);
		Contact(const Contact &copy);
		~Contact(void);

		// Getters
		const std::string		&getFirstName(void) const;
		const std::string		&getLastName(void) const;
		const std::string		&getNickname(void) const;
		const std::string		&getPhoneNumber(void) const;
		const std::string		&getDarkestSecret(void) const;

		// Methods
		void			printMembers(void) const;
		bool			areFieldsFilled(void) const;
} ;

#endif
