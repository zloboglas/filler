/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:55:30 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:55:31 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*area;
	char		*cp;

	area = (char*)malloc(size);
	if (area == NULL)
		return (NULL);
	cp = area;
	while (size--)
		*cp++ = (char)0;
	return ((void*)area);
}
