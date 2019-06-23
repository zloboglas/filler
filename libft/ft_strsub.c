/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:57:24 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:57:25 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;

	if (s == NULL)
		return (NULL);
	substr = (char*)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	i = start;
	while (s[i] && i < len + start)
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[i - start] = '\0';
	return (substr);
}
