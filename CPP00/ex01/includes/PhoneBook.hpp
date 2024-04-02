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

		PhoneBook( int next_contact );
		~PhoneBook( void );

		void	add_contact( void );
		void	display_contact_list( void ) const;

	private :

		Contact	temporary_contact;
		Contact contact_entries[8];
		int			next_contact_to_write;

		void		padded_display(std::string info) const;
		void		get_entry_to_display( void ) const;
};

#endif
