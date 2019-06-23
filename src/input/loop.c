/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:23:51 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 12:13:43 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		skip_n(int size)
{
	char	buf[2];
	int		i;

	i = 0;
	while (i < size)
	{
		read(0, buf, 1);
		if (*buf != '\n')
			i++;
	}
	read(0, buf, 1);
}

void		read_token(char *line, int offset, t_token *token)
{
	int		i;
	int		skip;

	clear_token(token, offset);
	line = ft_strchr(line, ' ') + 1;
	token->height = ft_atoi(line);
	token->width = ft_atoi(ft_strchr(line, ' '));
	if (offset)
	{
		skip = 4 + token->width;
		skip_n(skip);
	}
	token->the = ft_memalloc(token->height * sizeof(char *));
	i = 0;
	while (i < token->height)
	{
		ft_get_next_line(0, &line);
		token->the[i] = (unsigned char *)line + offset;
		i++;
	}
}

int			loop(t_field *field)
{
	char	*line;
	int		res;

	while ((res = ft_get_next_line(0, &line)) > -1)
	{
		if (res == 0 && field->solved == LEAVE)
			return (0);
		if (!line)
			continue;
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			read_token(line, 4, field->board);
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_token(line, 0, field->token);
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}
