/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 21:56:54 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/04 14:58:07 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int		main(void)
{
	PhoneBook		phonebook;
	std::string		command;
	
	phonebook.displayContacts();
	while (std::cin.fail() == false)
	{
		std::cout << "Enter a command: ";
		getline(std::cin, command);
		if (command.empty() == true)
			continue ;

		if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "Enter an index: ";
			getline(std::cin, command);
			if (command.empty() == false)
				phonebook.search(std::stoi(command));
		}
		else if (command.compare("EXIT") == 0)
			break ;
		else
		{
			std::cout << "Not a valid command" << "\n\n";
			continue ;
		}
		if (std::cin.fail() == true)
			break;

		phonebook.displayContacts();
		std::cout << "\n";
	}
	phonebook.~PhoneBook();
	return (0);
}
