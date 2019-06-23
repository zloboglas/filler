/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:48:05 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 11:55:02 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int					check_place(t_field *field, t_point point)
{
	t_point		t;
	int			counter;

	counter = 0;
	t.x = 0;
	while (t.x < field->token->height)
	{
		t.y = 0;
		while (t.y < field->token->width)
		{
			if (ft_toupper(field->board->the[point.x + \
			t.x][point.y + t.y]) == field->enemy->id && \
			field->token->the[t.x][t.y] == '*')
				return (0);
			if (ft_toupper(field->board->the[point.x + t.x][point.y + \
			t.y]) == field->ally->id && field->token->the[t.x][t.y] == '*')
				counter++;
			t.y++;
		}
		t.x++;
	}
	if (counter == 1)
		return (1);
	else
		return (0);
}

static unsigned char		check_distance(t_field *field, t_point point)
{
	t_point			tmp;
	unsigned char	distance;
	unsigned char	tmpdist;

	distance = (unsigned char)(-1);
	tmp.x = 0;
	while (tmp.x < field->board->height)
	{
		tmp.y = 0;
		while (tmp.y < field->board->width)
		{
			if (ft_toupper(field->board->the[tmp.x][tmp.y]) == \
			field->enemy->id)
			{
				tmpdist = dist(point, tmp);
				if (tmpdist < distance)
				{
					distance = tmpdist;
				}
			}
			tmp.y++;
		}
		tmp.x++;
	}
	return (distance);
}

void						fill_solve_map(t_field *field)
{
	t_point		point;

	point.x = 0;
	while (point.x + field->token->height < field->board->height)
	{
		point.y = 0;
		while (point.y + field->token->width < field->board->width)
		{
			if (check_place(field, point))
			{
				field->solved = TRUE;
				field->solve_map->the[point.x][point.y] = \
				check_distance(field, point);
			}
			point.y++;
		}
		point.x++;
	}
	if (field->solved != TRUE)
		field->solved = LEAVE;
}
