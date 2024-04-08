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
	Point a(0.0, 0.0);
	Point b(12.24, 8.56);
	Point c(24.42, 12.3);
	Point point(8.8, 5.5);

	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}

	point = Point(2.5, 0.5);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}

	point = Point(0, 1.7);
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

	point = Point(24.42, 12.3);
	if (bsp(a, b, c, point) == true) {
		std::cout << "The point is inside the triangle" << std::endl;
	} else {
		std::cout << "The point is not inside the triangle" << std::endl;
	}
	return 0;
}
