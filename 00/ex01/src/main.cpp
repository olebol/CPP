/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 21:56:54 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/03 23:37:48 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int		main(void)
{
	PhoneBook		phonebook;
	std::string		command;
	
	while (1)
	{
		std::cout << "Enter a command: ";
		getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
		{
			phonebook.displayContacts();
			std::cout << "Enter an index: ";
			getline(std::cin, command);
			phonebook.search(std::stoi(command));
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Not a valid command" << "\n";
	}
	phonebook.~PhoneBook();
	return (0);
}
