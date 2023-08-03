/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 19:57:53 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/03 23:28:41 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::printMembers(void)
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

bool	Contact::areFieldsCorrect(void)
{
	if ((this->_firstName.length() == 0)
		|| (this->_lastName.length() == 0)
		|| (this->_nickname.length() == 0)
		|| (this->_phoneNumber.length() == 0)
		|| (this->_darkestSecret.length() == 0))
	{
		return (false);
	}
	return (true);
}

// #############################################################################
// ################################ CONSTRUCTORS ###############################
// #############################################################################

Contact::Contact(void)
	:	_firstName(""),
		_lastName(""),
		_nickname(""),
		_phoneNumber(""),
		_darkestSecret("")
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
	:	_firstName(copy.getFirstName()),
		_lastName(copy.getLastName()),
		_nickname(copy.getNickname()),
		_phoneNumber(copy.getPhoneNumber()),
		_darkestSecret(copy.getDarkestSecret())
{ }

Contact::~Contact(void)
{ }

// #############################################################################
// ################################## SETTERS ##################################
// #############################################################################

void	Contact::setFirstName(std::string &newFirstName)
{
	this->_firstName = newFirstName;
}

void	Contact::setLastName(std::string &newLastName)
{
	this->_lastName = newLastName;
}

void	Contact::setNickname(std::string &newNickname)
{
	this->_nickname = newNickname;
}

void	Contact::setPhoneNumber(std::string &newPhoneNumber)
{
	this->_phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(std::string &newDarkestSecret)
{
	this->_darkestSecret = newDarkestSecret;
}

// #############################################################################
// ################################## WETTERS ##################################
// #############################################################################

std::string		&Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string		&Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string		&Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string		&Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string		&Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}
