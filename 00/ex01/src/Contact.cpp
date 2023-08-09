/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 19:57:53 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 21:07:13 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::printMembers(void) const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

bool	Contact::areFieldsFilled(void) const
{
	if ((_firstName.length() == 0)
		|| (_lastName.length() == 0)
		|| (_nickname.length() == 0)
		|| (_phoneNumber.length() == 0)
		|| (_darkestSecret.length() == 0))
	{
		return (false);
	}
	return (true);
}

// #############################################################################
// ################################ CONSTRUCTORS ###############################
// #############################################################################

Contact::Contact(void)
	:	_firstName(),
		_lastName(),
		_nickname(),
		_phoneNumber(),
		_darkestSecret()
{ }

Contact::Contact(const std::string &newFirstName, const std::string &newLastName, \
				const std::string &newNickname, const std::string &newPhoneNumber, \
				const std::string &newDarkestSecret)
	:	_firstName(newFirstName),
		_lastName(newLastName),
		_nickname(newNickname),
		_phoneNumber(newPhoneNumber),
		_darkestSecret(newDarkestSecret)
{ }

Contact::Contact(const Contact &copy)
	:	_firstName(copy._firstName),
		_lastName(copy._lastName),
		_nickname(copy._nickname),
		_phoneNumber(copy._phoneNumber),
		_darkestSecret(copy._darkestSecret)
{ }

Contact::~Contact(void)
{ }

// #############################################################################
// ################################## WETTERS ##################################
// #############################################################################

const std::string		&Contact::getFirstName(void) const
{
	return (_firstName);
}

const std::string		&Contact::getLastName(void) const
{
	return (_lastName);
}

const std::string		&Contact::getNickname(void) const
{
	return (_nickname);
}

const std::string		&Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

const std::string		&Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}
