/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:01:26 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 20:46:45 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <deque>

template <typename T, class Container = std::deque<T>>
class MutantStack
{
	protected:
		// Private Attributes
		Container		c;

	public:
		// Constructors and Destructors
		MutantStack(void);
		MutantStack(const MutantStack &rhs);
		MutantStack &operator=(const MutantStack &rhs);
		~MutantStack(void);

		// Element Access
		T 		&top(void);
		
		// Capacity
		bool	empty(void) const;
		size_t	size() const;

		// Modifiers
		void	push(const T &val);
		void	pop(void);
} ;

#include "./MutantStack.tpp"


#endif
