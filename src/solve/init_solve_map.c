/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solve_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:00:48 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 12:00:57 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			foo(t_field *field)
{
	int			i;
	int			j;

	field->solve_map->inited = TRUE;
	field->solve_map->the = (unsigned char **)malloc(sizeof(char *) * \
		field->solve_map->height);
	i = 0;
	while (i < field->solve_map->height)
	{
		field->solve_map->the[i] = (unsigned char *)malloc(sizeof(char) * \
			field->solve_map->width);
		j = 0;
		while (j < field->solve_map->width)
		{
			field->solve_map->the[i][j] = (unsigned char)(-1);
			j++;
		}
		i++;
	}
}

void				init_solve_map(t_field *field)
{
	int			i;
	int			j;

	field->solve_map->height = field->board->height;
	field->solve_map->width = field->board->width;
	if (field->solve_map->inited == FALSE)
	{
		foo(field);
	}
	else
	{
		i = 0;
		while (i < field->solve_map->height)
		{
			j = 0;
			while (j < field->solve_map->width)
			{
				field->solve_map->the[i][j] = (unsigned char)(-1);
				j++;
			}
			i++;
		}
	}
}
