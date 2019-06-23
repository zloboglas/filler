/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:03:05 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 12:03:07 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		n;
	size_t		i;

	n = ft_strlen(s);
	i = n + 1;
	while (i > 0)
	{
		if (*(s + i - 1) == (char)c)
			return ((void*)(s + i - 1));
		i--;
	}
	return (NULL);
}
