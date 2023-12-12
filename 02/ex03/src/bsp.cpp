/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:36:01 by opelser           #+#    #+#             */
/*   Updated: 2023/12/12 19:42:59 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include "../include/Fixed.hpp"

#include <iostream>

// Shoelace method
static float	getArea(const Point &a, const Point &b, const Point &c)
{
	float		area;

	area = a.getX() * (b.getY() - c.getY());
	area += b.getX() * (c.getY() - a.getY());
	area += c.getX() * (a.getY() - b.getY());

	if (area < 0)
		area *= -1;

	return (area / 2);
}

// Why no references? Ask 42.
bool	bsp(const Point a, const Point b, 
			const Point c, const Point point)
{
	const float		area_abc = getArea(a, b, c);
	const float		area_pab = getArea(point, a, b);
	const float		area_pbc = getArea(point, b, c);
	const float		area_pca = getArea(point, c, a);

	if (area_abc == area_pab + area_pbc + area_pca)
		return (true);
	else
		return (false);
}
