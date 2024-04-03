/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:20:01 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/02 14:20:02 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	no_arg(void)
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return ;
}

void	transform_current_arg(std::string current_arg)
{
	char	c;

	current_arg.erase(current_arg.find_last_not_of(" ") + 1);
	current_arg.erase(0, current_arg.find_first_not_of(" "));
	for (int i = 0; current_arg[i] != '\0'; ++i) {
		c = toupper(current_arg[i]);	
		current_arg[i] = c;
	}
	std::cout << current_arg;
	return ;
}

int	main(int ac, char **av)
{
	std::string	current_arg;

	if (ac == 1) {
		no_arg();
		return (0);
	}
	for (int i = 1; i < ac; ++i) {
		current_arg = av[i];
		transform_current_arg(current_arg);
		if (i < ac - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}
