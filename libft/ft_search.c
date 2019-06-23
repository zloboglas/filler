/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:51:23 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/13 19:51:25 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree				*ft_search(t_tree *current,
	void *data, int (*cmp)(void*, void*))
{
	int			compare;

	if (current == NULL)
		return (NULL);
	compare = cmp(data, current->data);
	if (compare == 0)
		return (current);
	else if (compare < 0)
		return (ft_search(current->left, data, cmp));
	else
		return (ft_search(current->right, data, cmp));
}
