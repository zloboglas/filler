/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:53:51 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:53:52 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strnumlen(const char *str, int i)
{
	int		ln;

	ln = i;
	while (str[ln] <= '9' && str[ln] >= '0')
		ln++;
	return (ln - i);
}

static int		skipstr(const char *str, int *sign)
{
	int		i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*sign = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

static int		detectlongstr(const char *str, int i, int sign)
{
	int		ln;

	ln = strnumlen(str, i);
	if (sign)
	{
		if (ln > 19 || (ln == 19 && (ft_strcmp(str + i,
"9223372036854775808") > 0)))
			return (0);
	}
	else
	{
		if (ln > 19 || (ln == 19 && (ft_strcmp(str + i,
"9223372036854775807") > 0)))
			return (-1);
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		res;
	int				flag;

	sign = 0;
	i = skipstr(str, &sign);
	flag = detectlongstr(str, i, sign);
	if (flag != 1)
		return (flag);
	res = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return ((sign) ? (int)-res : (int)res);
		else
			res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((sign) ? (int)-res : (int)res);
}
