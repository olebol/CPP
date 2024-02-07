/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StopWatch.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:24:37 by opelser           #+#    #+#             */
/*   Updated: 2024/02/07 15:44:45 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOPWATCH_HPP
# define STOPWATCH_HPP

# include <string>
# include <chrono>

class StopWatch
{
	private:
		// Private Attributes
		long long		_start;
		long long		_elapsed;
		
	public:
		// Constructors and Destructors
		StopWatch(void);
		StopWatch(const StopWatch &rhs);
		StopWatch &operator=(const StopWatch &rhs);
		~StopWatch(void);

		// Getters
		long long		getElapsed(void) const;

		// Public Methods
		void		start(void);
		void		stop(void);
} ;

#endif
