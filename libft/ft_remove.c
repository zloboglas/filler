/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:38:40 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/13 19:38:42 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_tree		*ft_findmin(t_tree *p)
{
	return (p->left ? ft_findmin(p->left) : p);
}

static t_tree		*ft_removemin(t_tree *p)
{
	if (p->left == NULL)
		return (p->right);
	p->left = ft_removemin(p->left);
	return (ft_balance(p));
}

static void			ft_delete(t_tree *p)
{
	free(p);
}

t_tree				*ft_remove(t_tree *p,
	void *data, int (*cmp)(void *, void *))
{
	int		compare;
	t_tree	*q;
	t_tree	*r;
	t_tree	*min;

	if (!p)
		return (0);
	compare = cmp(data, p->data);
	if (compare < 0)
		p->left = ft_remove(p->left, data, cmp);
	else if (compare > 0)
		p->right = ft_remove(p->right, data, cmp);
	else
	{
		q = p->left;
		r = p->right;
		ft_delete(p);
		if (!r)
			return (q);
		min = ft_findmin(r);
		min->right = ft_removemin(r);
		min->left = q;
		return (ft_balance(min));
	}
	return (ft_balance(p));
}
