/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:30:05 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 15:30:06 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include "main.hpp"

class Contact {

	public:

		Contact( void );
		~Contact( void );

		int		is_set;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;

		int		fetch_contact(void);
		void	copy_contact(Contact contact_to_copy);
		void	display_contact(void) const;

	private:

		std::string	phone_number;
		std::string	darkest_secret;

		std::string	fetch_input(std::string to_display, int *is_set);
};

#endif
