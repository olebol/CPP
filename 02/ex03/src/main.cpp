/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:26:40 by opelser           #+#    #+#             */
/*   Updated: 2023/12/12 19:43:19 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

#include <iostream>

int main(void)
{
	Point	point(0.0f, 0.1f);

	Point	triangle[3] = 
	{
		Point(0.0f, 0.0f),
		Point(0.0f, 1.0f),
		Point(1.0f, 0.0f)
	} ;

	std::cout << "Triangle is (" << triangle[0].getX() << ", " << triangle[0].getY() << "), ";
	std::cout << "(" << triangle[1].getX() << ", " << triangle[1].getY() << "), ";
	std::cout << "(" << triangle[2].getX() << ", " << triangle[2].getY() << ")\n" << std::endl;

	std::cout << "Point is (" << point.getX() << ", " << point.getY() << ")\n" << std::endl;

	if (bsp(triangle[0], triangle[1], triangle[2], point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	return (0);
}