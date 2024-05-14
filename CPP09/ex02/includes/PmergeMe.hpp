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

#include <cstddef>
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

		void				_vecMergeSort( std::vector<int>& current, size_t itSize);
		void				_vecInsert( std::vector<int>& current, size_t itSize);
		void				_permutePairs( std::vector<int>& current, size_t itSize);
		void				_insertReminder( std::vector<int>& current, size_t itSize);
		void				_insert(std::vector<int>& current, const int_it& begin,
								const int_it& end, const int_it& where);
		void				_getNextJacobsthal(int &actual, int &prev);
		inline bool	_checkReminder(std::vector<int>& current, size_t itSize) const;

		std::vector<int>		_intVect;
		std::list<int>			_intList;	
		unsigned int				_vectorTime;
		unsigned int				_listTime;

};

#endif
