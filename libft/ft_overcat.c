/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:19:39 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/17 18:19:59 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_overcat(char **dst, char *src)
{
	char		*tmp;

	tmp = ft_strjoin(*dst, src);
	if (*dst != NULL)
		free(*dst);
	*dst = tmp;
}
