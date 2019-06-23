/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:21:41 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 12:12:01 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_token(t_token **token)
{
	if (*token)
	{
		if ((*token)->the)
		{
			free((*token)->the);
			(*token)->the = NULL;
		}
		free(*token);
		*token = NULL;
	}
}

void		free_player(t_player **player)
{
	if (*player)
	{
		if ((*player)->position)
		{
			free((*player)->position);
			(*player)->position = NULL;
		}
		free(*player);
		*player = NULL;
	}
}

void		free_field(t_field **field)
{
	if (*field)
	{
		free_token(&((*field)->board));
		free_token(&((*field)->token));
		free_token(&((*field)->solve_map));
		free_player(&((*field)->ally));
		free_player(&((*field)->enemy));
		free(*field);
		*field = NULL;
	}
}

void		clear_token(t_token *token, int offset)
{
	int				i;
	unsigned char	*str;

	if (!token->the)
		return ;
	i = 0;
	while (i < token->height)
	{
		str = token->the[i] - offset;
		ft_strdel((char**)&str);
		i++;
	}
	ft_memdel((void **)&token->the);
	token->the = NULL;
}
