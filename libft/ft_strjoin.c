/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:57:35 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:57:37 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		ln1;
	size_t		ln2;
	char		*catstr;
	size_t		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		ln1 = 0;
	else
		ln1 = ft_strlen(s1);
	if (s2 == NULL)
		ln2 = 0;
	else
		ln2 = ft_strlen(s2);
	if (!(catstr = (char*)malloc(ln1 + ln2 + 1)))
		return (NULL);
	i = -1;
	while (++i < ln1)
		catstr[i] = s1[i];
	i = -1;
	while (++i < ln2)
		catstr[i + ln1] = s2[i];
	catstr[ln1 + ln2] = '\0';
	return (catstr);
}
