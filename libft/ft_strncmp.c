/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:53:40 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:53:41 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
	{
		if (*s1 == 0 && *s2 == 0)
			return (0);
		else
			return (ft_strncmp((s1 + 1), (s2 + 1), n - 1));
	}
}
