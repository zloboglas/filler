/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:01:22 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 14:34:51 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					my_sqrt(int x)
{
	int left;
	int right;
	int res;
	int mid;

	if (x <= 0)
		return (0);
	left = 1;
	right = x / 2 + 1;
	res = -1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (mid <= x / mid)
		{
			left = mid + 1;
			res = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (res);
}

int					dist(t_point one, t_point two)
{
	int		distance;

	distance = my_sqrt((one.x - two.x) * (one.x - two.x) + \
	(one.y - two.y) * (one.y - two.y));
	return ((distance < 127) ? distance : 127);
}

static void			pair_eq(t_point *point, int v1, int v2)
{
	point->x = v1;
	point->y = v2;
}

t_point				find_answer(t_field *field)
{
	unsigned char	distance;
	t_point			answer;
	t_point			point;

	pair_eq(&answer, 0, 0);
	distance = (unsigned char)-1;
	point.x = 0;
	while (point.x < field->solve_map->height)
	{
		point.y = 0;
		while (point.y < field->solve_map->width)
		{
			if (field->solve_map->the[point.x][point.y] < distance)
			{
				distance = field->solve_map->the[point.x][point.y];
				pair_eq(&answer, point.x, point.y);
			}
			point.y++;
		}
		point.x++;
	}
	return (answer);
}

t_point				solve(t_field *field)
{
	t_point		answer;

	fill_solve_map(field);
	answer = find_answer(field);
	return (answer);
}
