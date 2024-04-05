/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitute.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:20:22 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/04 13:20:22 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Substitute.hpp"

Substitute::Substitute(const char *infile, const char *string_to_find,
		const char *string_to_replace) : _file(infile), _string_to_find(string_to_find),
		_string_to_replace(string_to_replace) {
	return ;
}

Substitute::~Substitute( void ) {
	return ;
}

int Substitute::_init_instream( void ) {
	this->_instream.open(_file.c_str());	
	if (this->_instream.fail()) {
		std::cout << "Substitute: Error while opening: " << _file << ": "
			<< strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}

int Substitute::_init_outstream( void ) {
	this->_outstream.open((_file.append(".replace").c_str()));	
	if (this->_outstream.fail()) {
		std::cout << "Substitute: Error while opening: " << _file << ": "
			<< strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}

int	Substitute::init_streams( void ) {
	int	return_value;

	return_value = this->_init_instream();
	if (return_value == 0) {
		return_value = this->_init_outstream();
	}
	return (return_value);
}

void Substitute::substitute_buffer( void ) {
	std::size_t	needle;
	std::string buffer_cpy;

	_buffer << _instream.rdbuf();
	buffer_cpy = _buffer.str();
	while ((needle = buffer_cpy.find(_string_to_find)) != std::string::npos)
	{
		buffer_cpy.erase(needle, (this->_string_to_find.size()));
		buffer_cpy.insert(needle, _string_to_replace);
		needle = buffer_cpy.find(_string_to_find);
	}
	_outstream << buffer_cpy;
	return ;
}
