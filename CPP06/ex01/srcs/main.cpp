/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:49:12 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/27 18:49:13 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serialize.hpp>
#include <iostream>

int main(void) {
	t_data data = {
		.a = 42,
		.b = 42.42f,
		.s = "Hello World !"
	};
	t_data *data_ptr = &data;
	uintptr_t raw;

	std::cout << "Before Serialization : " << std::endl;
	std::cout << "data.a : " << data_ptr->a << std::endl;
	std::cout << "data.b : " << data_ptr->b << std::endl;
	std::cout << "data.s : " << data_ptr->s << std::endl;
	raw = Serialize::serialize(data_ptr);
	data_ptr = NULL;
	data_ptr = Serialize::deserialize(raw);
	std::cout << "After Serialization : " << std::endl;
	std::cout << "data.a : " << data_ptr->a << std::endl;
	std::cout << "data.b : " << data_ptr->b << std::endl;
	std::cout << "data.s : " << data_ptr->s << std::endl;
}
