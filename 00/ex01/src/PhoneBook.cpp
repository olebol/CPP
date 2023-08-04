/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 01:00:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/04 15:06:49 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
// #include <cctype>

#define HORIZONTAL_EDGE	"---------------------------------------------\n"
#define EMPTY_CONTACT	       "           |            |            |\n"
#define TABLE_INFO		"| ID |    NAME    | LAST  NAME |  NICKNAME  |\n"

bool	isValidContact(Contact &contact)
{
	const std::string phoneNumber = contact.getPhoneNumber();

	for (int i = 0; i < (int) phoneNumber.length(); i++)
	{
		if (std::isdigit((int) phoneNumber[i]) == false)
		{
			std::cout << "Error creating contact!" << "\n";
			std::cout << "Please enter a valid phone number" << "\n";
			return (false);
		}
	}

	if (contact.areFieldsFilled() == false)
	{
		std::cout << "Error creating contact!" << "\n";
		std::cout << "Fields cannot be empty" << "\n";
		return (false);
	}
	return (true);
}

void	PhoneBook::add(void)
{
	std::string		input;
	Contact			&currentContact = this->_contacts[this->_index];

	std::cout << "First Name: ";
	std::getline(std::cin, input);
	currentContact.setFirstName(input);

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	currentContact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	currentContact.setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	currentContact.setPhoneNumber(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	currentContact.setDarkestSecret(input);

	std::cout << "\n";
	if (isValidContact(currentContact) == false)
	{
		currentContact.resetStrings();
		return ;
	}
	else
		std::cout << "Contact " << this->_index + 1 << " succesfully created" << "\n";

	this->_index++;
	if (this->_index > 7)
		this->_index = 0;
}

static void		printField(std::string &field, std::string end)
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

void	PhoneBook::displayContacts(void)
{
	std::cout << HORIZONTAL_EDGE;
	std::cout << TABLE_INFO;
	std::cout << HORIZONTAL_EDGE;
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
	std::cout << HORIZONTAL_EDGE;
}

void	PhoneBook::search(int index)
{
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
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i].~Contact();
}
