/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:22:57 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/09 10:22:59 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			pre_read(t_field *field)
{
	char		*line;

	if (ft_get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
		!ft_strncmp(line, "$$$ exec p", 9) &&
		(line[10] == '1' || line[10] == '2'))
	{
		field->ally->id = (char)(line[10] == '1' ? 'O' : 'X');
		field->enemy->id = (char)(line[10] == '1' ? 'X' : 'O');
		ft_strdel(&line);
		return (1);
	}
	else
	{
		if (line)
			ft_strdel(&line);
	}
	return (0);
}
