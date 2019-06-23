/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:58:13 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:58:15 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(unsigned int un)
{
	if (un == 0)
		return (0);
	else
		return (1 + intlen(un / 10));
}

static char		*itoater(unsigned int un, short int sign)
{
	char	*str;
	int		ln;
	int		i;

	ln = intlen(un) + sign + 1;
	str = ft_strnew(ln);
	if (str == NULL)
		return (NULL);
	i = ln - 2;
	if (sign)
	{
		str[0] = '-';
		ln--;
	}
	while (i >= 0 + sign)
	{
		str[i] = '0' + un % 10;
		un /= 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	unsigned int	un;
	short int		sign;
	char			*str;

	if (n == 0)
	{
		str = (char*)ft_memalloc(2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		un = n * -1;
		sign = 1;
	}
	else
	{
		sign = 0;
		un = n;
	}
	return (itoater(un, sign));
}
