/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:45:54 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 16:48:33 by opelser          ###   ########.fr       */
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
	return (std::find(container.begin(), container.end(), value));
}

#endif
