/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:17:58 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 09:11:09 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_point		*create_point(void)
{
	t_point			*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x = -1;
	point->y = -1;
	return (point);
}

static t_player		*create_player(void)
{
	t_player		*player;

	player = (t_player*)malloc(sizeof(t_player));
	player->id = 'n';
	player->position = create_point();
	return (player);
}

static t_token		*create_token(void)
{
	t_token		*token;

	token = (t_token*)malloc(sizeof(t_token));
	token->height = 0;
	token->width = 0;
	token->inited = 0;
	token->the = NULL;
	return (token);
}

t_field				*create_field(void)
{
	t_field		*field;

	field = (t_field*)malloc(sizeof(t_field));
	field->ally = create_player();
	field->enemy = create_player();
	field->board = create_token();
	field->solve_map = create_token();
	field->token = create_token();
	field->solved = FALSE;
	return (field);
}
