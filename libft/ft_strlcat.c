/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:52:30 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:52:32 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		srclen;
	size_t		dstlen;
	size_t		i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	while (i + 1 < size)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	dst[i] = '\0';
	return (srclen + ((dstlen < size) ? dstlen : size));
}
