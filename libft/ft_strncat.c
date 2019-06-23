/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:52:18 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:52:21 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		ln1;
	size_t		ln2;

	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	if (n > ln2)
		n = ln2;
	ft_strncpy(s1 + ft_strlen(s1), s2, n);
	s1[ln1 + n] = '\0';
	return (s1);
}
