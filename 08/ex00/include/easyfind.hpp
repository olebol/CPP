/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:45:54 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 16:20:43 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>

# include <iterator>
# include <algorithm>

template <typename T>
typename T::iterator		easyfind(T &container, int value)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), value);

	if (iter == container.end())
		throw (std::runtime_error("Value not found in container"));
	
	return (iter);
}

#endif
