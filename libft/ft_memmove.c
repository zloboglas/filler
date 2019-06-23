/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:50:30 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:50:32 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*go_back(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = len;
	while (i > 0)
	{
		i--;
		((char*)dst)[i] = ((char*)src)[i];
	}
	return (dst);
}

static	void	*just_go(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;
	size_t	i;
	int		flag;

	if ((void*)src == dst)
		return (dst);
	flag = 0;
	i = 0;
	tmp = (void*)src + len - 1;
	while (i < len && !flag)
	{
		if (tmp == dst + i)
			flag = 1;
		i++;
	}
	if (flag)
		return (go_back(dst, src, len));
	else
		return (just_go(dst, src, len));
}
