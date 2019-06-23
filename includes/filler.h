/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:51:22 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/16 12:09:50 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define LEAVE 2

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_player
{
	char			id;
	t_point			*position;
}					t_player;

typedef struct		s_token
{
	int				width;
	int				height;
	int				inited;
	unsigned char	**the;
}					t_token;

typedef struct		s_field
{
	t_token			*board;
	t_token			*solve_map;
	t_token			*token;
	t_player		*ally;
	t_player		*enemy;
	char			solved;
}					t_field;

t_field				*create_field();
int					pre_read(t_field *field);
int					loop(t_field *field);

int					dist(t_point one, t_point two);

void				compute(t_field *field);
void				init_solve_map(t_field *field);
void				fill_solve_map(t_field *field);
t_point				solve(t_field *field);

void				free_token(t_token **token);
void				free_player(t_player **player);
void				free_field(t_field **field);

void				clear_token(t_token *token, int offset);

#endif
