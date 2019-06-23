/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:57:48 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:57:49 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	spy(size_t *begin, size_t *end, char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	*begin = i;
	*end = i + 1;
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			*end = i + 1;
		i++;
	}
}

char			*ft_strtrim(char const *s)
{
	size_t		begin;
	size_t		end;
	size_t		alloc;
	char		*dst;

	if (s == NULL)
		return (NULL);
	spy(&begin, &end, s);
	alloc = end - begin + 1;
	dst = (char*)malloc(alloc);
	if (!dst)
		return (NULL);
	ft_strncpy(dst, &s[begin], end - begin);
	dst[end - begin] = '\0';
	return (dst);
}
