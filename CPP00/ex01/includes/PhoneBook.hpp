/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:24:36 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 15:24:37 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {

	public :

		PhoneBook( void );
		~PhoneBook( void );

	private :

		Contact contact_entries[8];
		int			next_contact_to_write;
};

#endif
