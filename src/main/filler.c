/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:00:24 by dlabadie          #+#    #+#             */
/*   Updated: 2019/05/09 11:00:26 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		send_output(t_point answer)
{
	ft_putnbr(answer.x);
	ft_putchar(' ');
	ft_putnbr(answer.y);
	ft_putchar('\n');
}

int				main(void)
{
	t_field		*field;
	t_point		answer;

	field = create_field();
	if (pre_read(field))
	{
		while (loop(field))
		{
			field->solved = FALSE;
			compute(field);
			answer = solve(field);
			send_output(answer);
		}
	}
	free_field(&field);
	return (0);
}
