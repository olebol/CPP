/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/09 17:26:40 by opelser       #+#    #+#                 */
/*   Updated: 2023/08/11 18:03:14 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int		main(void)
{
	Harl		lemongrab;

	lemongrab.complain("debug");
	lemongrab.complain("info");
	lemongrab.complain("warning");
	lemongrab.complain("error");
	return (0);
}