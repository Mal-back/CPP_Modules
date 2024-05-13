/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:19:30 by purmerinos        #+#    #+#             */
/*   Updated: 2024/05/10 18:19:30 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

#include <exception>
#include <list>
#include <utility>
#include <vector>

typedef std::pair<int, int> pairs;
typedef std::vector<int>::iterator int_it;
typedef std::vector<pairs>::iterator pairs_it;

class PmergeMe {

	public :
		PmergeMe( void );
		~PmergeMe( void );

		class wrongInput : public std::exception {
			public : 
				const char*	what() const throw();
		};

		class doubleOccurence : public std::exception {
			public : 
				const char*	what() const throw();
		};

		void	vectorSort(char **numbers, int ac);
		void	listSort(char **numbers);

	private :

		PmergeMe(const PmergeMe& to_copy);
		PmergeMe&		operator=(const PmergeMe& rhs);

		std::vector<int>	_vecMergeSort( std::vector<int>& current);

		std::vector<int>		_intVect;
		std::list<int>			_intList;	
		unsigned int				_vectorTime;
		unsigned int				_listTime;

};

#endif
