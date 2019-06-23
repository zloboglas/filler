/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmfirstn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:23:51 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/11 17:25:28 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rmfirstn(char **str, size_t n)
{
	size_t		ln;
	char		*tmp2;

	ln = ft_strlen(*str);
	tmp2 = ft_strnew(ln - n + 1);
	ft_strcat(tmp2, *str + n + 1);
	free(*str);
	*str = tmp2;
}
