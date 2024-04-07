/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:37:06 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/07 18:37:07 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	compute_area(Point vertice1, Point vertice2, Point vertice3)
{
	float res;

	res = ((vertice1.getXAsFloat() * (vertice2.getYAsFloat() - vertice3.getYAsFloat()))
		+ (vertice2.getXAsFloat() * (vertice3.getYAsFloat() - vertice1.getYAsFloat()))
		+ (vertice3.getXAsFloat() * (vertice1.getYAsFloat() - vertice2.getYAsFloat()))) / 2.0;
	if (res < 0)
	{
		res *= -1;
	}
	return res;
}

bool	is_on_edge(Point const a, Point const b, Point const point)
{
	Point v(b.getXAsFloat() - a.getXAsFloat(), b.getYAsFloat() - a.getYAsFloat());
	Point w(point.getXAsFloat() - a.getXAsFloat(), point.getYAsFloat() - a.getYAsFloat());
	float	wedge = v.getXAsFloat() * w.getYAsFloat() - v.getYAsFloat() * w.getXAsFloat();
	return (wedge == 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area[4];

	if (is_on_edge(a, b, point) || is_on_edge(b, c, point) || is_on_edge(a, c, point)) {
		return (false);
	}
	area[0] = compute_area(a, b, c);
	area[1] = compute_area(a, b, point);
	area[2] = compute_area(a, point, c);
	area[3] = compute_area(point, b, c);

	if (area[0] == area[1] + area[2] + area[3]) {
		return (true);
	} else {
	return (false);
	}
}
