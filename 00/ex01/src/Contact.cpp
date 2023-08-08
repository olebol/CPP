/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 19:57:53 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/08 16:27:03 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::printMembers(void)
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

bool	Contact::areFieldsFilled(void)
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

void	Contact::resetStrings(void)
{
	_firstName.erase();
	_lastName.erase();
	_nickname.erase();
	_phoneNumber.erase();
	_darkestSecret.erase();
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

Contact::Contact(std::string &newFirstName, std::string &newLastName, \
				std::string &newNickname, std::string &newPhoneNumber, \
				std::string &newDarkestSecret)
	:	_firstName(newFirstName),
		_lastName(newLastName),
		_nickname(newNickname),
		_phoneNumber(newPhoneNumber),
		_darkestSecret(newDarkestSecret)
{ }

Contact::Contact(Contact &copy)
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

std::string		&Contact::getFirstName(void)
{
	return (_firstName);
}

std::string		&Contact::getLastName(void)
{
	return (_lastName);
}

std::string		&Contact::getNickname(void)
{
	return (_nickname);
}

std::string		&Contact::getPhoneNumber(void)
{
	return (_phoneNumber);
}

std::string		&Contact::getDarkestSecret(void)
{
	return (_darkestSecret);
}
