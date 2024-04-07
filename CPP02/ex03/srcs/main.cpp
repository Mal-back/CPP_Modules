/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:20:48 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/05 18:20:49 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(1, 1);
	Point b(1, 3);
	Point c(3, 3);
	Point point(1.1, 2);

	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	point = Point(3, 3);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	point = Point(1, 1.7);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	point = Point(1.4, 1.7);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	point = Point(3.1, 0.5);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	return 0;
}
