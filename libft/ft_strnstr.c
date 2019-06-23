/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:53:16 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:53:18 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;
	size_t	lnh;

	lnh = ft_strlen(haystack);
	if (*needle == '\0')
		return ((char*)haystack);
	ln = ft_strlen(needle);
	if (ln > lnh || ln > len)
		return (NULL);
	i = 0;
	while (i <= len - ln && i < lnh)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
