/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:54:48 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 16:06:43 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void	swap(T &first, T &second)
{
	T	tmp;

	tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
T		min(const T &first, const T &second)
{
	return ((first < second) ? first : second);
}

template <typename T>
T		max(const T &first, const T &second)
{
	return ((first > second) ? first : second);
}

#endif
