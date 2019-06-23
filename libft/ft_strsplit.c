/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:31:01 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/17 17:31:03 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sublen(char const *s, char c)
{
	int	i;

	if (!s)
		return (0);
	if (!*s)
		return (0);
	i = 1;
	if (*s == c)
		i--;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (!*s)
			{
				s--;
				break ;
			}
			i++;
		}
		s++;
	}
	return (i);
}

static int	subclen(char const **s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (**s && **s != c)
	{
		(*s)++;
		i++;
	}
	return (i);
}

char static	**ar_checker(char **ar, int i)
{
	int	f;
	int j;

	j = i;
	f = 0;
	if (!ar)
		return (NULL);
	ar[i] = NULL;
	while (i--)
		if (ar[i] == NULL)
			f = 1;
	if (f)
	{
		while (j--)
			if (ar[j])
				ft_memdel((void *)ar[j]);
		free(ar);
	}
	return (f ? NULL : ar);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**rez;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = sublen(s, c);
	j = 0;
	rez = (char **)ft_memalloc((i + 1) * sizeof(char **));
	while (j < i && rez)
	{
		if (*s == c)
		{
			while (*s == c && *s)
				s++;
			if (!*s)
				s--;
		}
		len = subclen(&s, c);
		if ((rez[j] = ft_strnew(len)) != NULL)
			ft_strncat(rez[j++], s - len, len);
	}
	return (ar_checker(rez, i));
}
