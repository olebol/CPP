/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 21:27:13 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/04 15:11:41 by opelser       ########   odam.nl         */
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
		Contact(std::string &firstName, std::string &lastName, \
				std::string &nickname, std::string &phoneNumber, \
				std::string &darkestSecret);
		Contact(Contact &copy);
		~Contact(void);


		// Setters
		void			setFirstName(std::string &newFirstName);
		void			setLastName(std::string &newLastName);
		void			setNickname(std::string &newNickname);
		void			setPhoneNumber(std::string &newPhoneNumber);
		void			setDarkestSecret(std::string &newFirstName);

		// Getters
		std::string		&getFirstName(void);
		std::string		&getLastName(void);
		std::string		&getNickname(void);
		std::string		&getPhoneNumber(void);
		std::string		&getDarkestSecret(void);

		// Methods
		void			printMembers(void);
		bool			areFieldsFilled(void);
		void			resetStrings(void);
} ;

#endif
