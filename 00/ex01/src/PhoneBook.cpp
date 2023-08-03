/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/03 01:00:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/03 23:39:17 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

void	PhoneBook::add(void)
{
	std::string		tmp;
	Contact			&currentContact = this->_contacts[_index];

	std::cout << "First Name: ";
	std::getline(std::cin, tmp);
	currentContact.setFirstName(tmp);

	std::cout << "Last Name: ";
	std::getline(std::cin, tmp);
	currentContact.setLastName(tmp);

	std::cout << "Nickname: ";
	std::getline(std::cin, tmp);
	currentContact.setNickname(tmp);

	std::cout << "Phone number: ";
	std::getline(std::cin, tmp);
	currentContact.setPhoneNumber(tmp);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, tmp);
	currentContact.setDarkestSecret(tmp);

	if (currentContact.areFieldsCorrect() == false)
	{
		std::cout << "Error creating contact!" << "\n";
		std::cout << "Fields cannot be empty" << "\n";
		currentContact.~Contact();
	}

	this->_index++;
	if (this->_index < 8)
		this->_index = 0;
}

static void		printEdges(void)
{
	std::cout.width(45);
	std::cout.fill('-');
	std::cout << std::right << "\n";
	std::cout.fill(' ');
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
	printEdges();
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].areFieldsCorrect() == false)
			continue ;
		std::cout << "| " << i + 1 << " | ";
		printField(this->_contacts[i].getFirstName(), " | ");
		printField(this->_contacts[i].getLastName(), " | ");
		printField(this->_contacts[i].getNickname(), " |\n");
	}
	printEdges();
}

void	PhoneBook::search(int index)
{
	if (!(index >= 1 && index <= 8))
	{
		std::cout << index << "is not a valid index!" << "\n";
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
