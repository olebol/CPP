/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:01:26 by opelser           #+#    #+#             */
/*   Updated: 2024/02/01 21:58:17 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <deque>
# include <stack>

template <typename T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		// Constructors and Destructors
		MutantStack(void);
		MutantStack(const MutantStack &rhs);
		MutantStack &operator=(const MutantStack &rhs);
		~MutantStack(void);

		// Iterators
		typedef		typename Container::iterator			iterator;
		typedef		typename Container::reverse_iterator	reverse_iterator;
		
		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}

		reverse_iterator	rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}
} ;

#include "./MutantStack.tpp"

#endif
