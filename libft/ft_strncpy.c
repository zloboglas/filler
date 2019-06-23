/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:51:54 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:51:56 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	ln;

	ft_memcpy(dst, src, len);
	ln = ft_strlen(src);
	while (ln < len)
	{
		dst[ln] = '\0';
		ln++;
	}
	return (dst);
}
