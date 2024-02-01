/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:36:42 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 20:49:57 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/MutantStack.hpp"

int main(void)
{
	MutantStack<int>	mstack;

	std::cout << "mstack.empty(): " << mstack.empty() << std::endl;
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "mstack.top(): " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack.top() after pop: " << mstack.top() << std::endl;
	std::cout << std::endl;

	std::cout << "mstack.empty(): " << mstack.empty() << std::endl;
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << std::endl;

	return (0);
}
