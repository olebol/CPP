/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:15:50 by opelser           #+#    #+#             */
/*   Updated: 2024/01/31 16:27:29 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>

template <typename T>
void	iter(T *array, size_t length, void (*f)(const T &param))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	print(const T &param)
{
	std::cout << param << std::endl;
}

#endif
