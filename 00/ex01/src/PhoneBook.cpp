/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 01:00:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 21:08:27 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
// #include <cctype>

#define HORIZONTAL_EDGE	"---------------------------------------------\n"
#define EMPTY_CONTACT	       "           |            |            |\n"
#define TABLE_INFO		"| ID |    NAME    | LAST  NAME |  NICKNAME  |\n"

static bool		isPhoneValid(std::string &phoneNumber)
{
	for (int i = 0; i < (int) phoneNumber.length(); i++)
	{
		if (std::isdigit((int) phoneNumber[i]) == false)
		{
			std::cout << "Error creating contact!" << "\n";
			std::cout << "Please enter a valid phone number" << "\n";
			return (false);
		}
	}
	return (true);
}
static bool		isFieldEmpty(std::string field)
{
	if (field.empty() == true)
	{
		std::cout << "Error creating contact!" << "\n";
		std::cout << "Fields cannot be empty" << "\n";
		return (true);
	}
	return (false);
}

void	PhoneBook::add(void)
{
	std::string		first, last, nick, phone, secret;

	std::cout << "\n" << "First Name: ";
	std::getline(std::cin, first);
	if (isFieldEmpty(first) == true)
		return ;

	std::cout << "Last Name: ";
	std::getline(std::cin, last);
	if (isFieldEmpty(last) == true)
		return ;

	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	if (isFieldEmpty(nick) == true)
		return ;

	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	if (isFieldEmpty(phone) == true || isPhoneValid(phone) == false)
		return ;

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, secret);
	if (isFieldEmpty(secret) == true)
		return ;

	Contact newContact(first, last, nick, phone, secret);
	_contacts[_index] = newContact;
	std::cout <<  "\n" << "Contact " << this->_index + 1 << " succesfully created" << "\n";

	this->_index++;
	if (this->_index > 7)
		this->_index = 0;
}

static void		printField(const std::string &field, const std::string end)
{
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
	{
		std::cout.width(10);
		std::cout << std::left << field;
	}

	std::cout << end;
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << "\n" << HORIZONTAL_EDGE << TABLE_INFO << HORIZONTAL_EDGE;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "| " << i + 1 << "  | ";
		if (this->_contacts[i].areFieldsFilled() == false)
		{
			std::cout << EMPTY_CONTACT;
			continue ;
		}
		printField(this->_contacts[i].getFirstName(), " | ");
		printField(this->_contacts[i].getLastName(), " | ");
		printField(this->_contacts[i].getNickname(), " |\n");
	}
	std::cout << HORIZONTAL_EDGE << "\n";
}

void	PhoneBook::search(void) const
{
	std::string		input;
	int				index = 0;

	while (std::cin.fail() == false)
	{
		std::cout << "Enter an index: ";
		getline(std::cin, input);
		if (input.empty() == false)
		{
			index = std::stoi(input);
			break ;
		}
	}
	if (std::cin.fail() == true)
	{
		std::cout << "Input closed" << "\n";
		return ;
	}
	if (!(index >= 1 && index <= 8))
	{
		std::cout << index << "is not a valid index!" << "\n";
		return ;
	}
	if (this->_contacts[index - 1].areFieldsFilled() == false)
	{
		std::cout << "Contact " << index << " is empty" << "\n";
		return ;
	}
	this->_contacts[index - 1].printMembers();
}

// #############################################################################
// ################################ CONSTRUCTORS ###############################
// #############################################################################


PhoneBook::PhoneBook(void)
	: _index(0)
{ }

PhoneBook::~PhoneBook()
{ }
