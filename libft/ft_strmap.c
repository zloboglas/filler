/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:56:43 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:56:44 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t					ln;
	unsigned int			i;
	char					*newstr;

	if (s == NULL || f == NULL)
		return (NULL);
	ln = ft_strlen(s);
	newstr = (char*)malloc(ln + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < ln)
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
