/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:55:49 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:55:50 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*area;

	if (size + 1 == 0)
		return (NULL);
	area = (char*)ft_memalloc(size + 1);
	if (area == NULL)
		return (NULL);
	return (area);
}
