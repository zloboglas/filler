/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpfirstn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:25:48 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/11 17:25:50 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_cpfirstn(char **dst, const char *src, size_t n)
{
	if (*dst != NULL)
	{
		free(*dst);
		*dst = NULL;
	}
	*dst = ft_strnew(n + 1);
	ft_strncat(*dst, src, n);
}
