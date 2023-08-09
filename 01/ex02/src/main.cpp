/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/07 22:15:50 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/09 17:15:42 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*ptr = &str;
	std::string		&ref = str;

	std::cout << "str : " << &str << std::endl;
	std::cout << "ptr : " << ptr << std::endl;
	std::cout << "ref : " << &ref << std::endl;

	std::cout << "\n";

	std::cout << "str : " << str << std::endl;
	std::cout << "ptr : " << *ptr << std::endl;
	std::cout << "ref : " << ref << std::endl;

	return (0);
}
