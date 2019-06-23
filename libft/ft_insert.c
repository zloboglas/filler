/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:43:01 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/13 19:43:04 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree				*ft_insert(t_tree *p, t_tree *ins,
	void *data, int (*cmp)(void *, void *))
{
	if (!p)
		return (ins);
	else if (cmp(data, p->data) < 0)
		p->left = ft_insert(p->left, ins, data, cmp);
	else
		p->right = ft_insert(p->right, ins, data, cmp);
	return (ft_balance(p));
}
