/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:37:18 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/13 19:37:22 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_bfactor(t_tree *p)
{
	int		hl;
	int		hr;

	hl = (p->left) ? (p->left->height) : 0;
	hr = (p->right) ? (p->right->height) : 0;
	return (hr - hl);
}

static void				ft_fixheight(t_tree *p)
{
	unsigned char	hl;
	unsigned char	hr;

	hl = (p->left) ? (p->left->height) : 0;
	hr = (p->right) ? (p->right->height) : 0;
	p->height = ((hl > hr) ? hl : hr) + 1;
}

static t_tree			*ft_rotateright(t_tree *p)
{
	t_tree			*q;

	q = p->left;
	p->left = q->right;
	q->right = p;
	ft_fixheight(p);
	ft_fixheight(q);
	return (q);
}

static t_tree			*ft_rotateleft(t_tree *q)
{
	t_tree			*p;

	p = q->right;
	q->right = p->left;
	p->left = q;
	ft_fixheight(q);
	ft_fixheight(p);
	return (p);
}

t_tree					*ft_balance(t_tree *p)
{
	ft_fixheight(p);
	if (ft_bfactor(p) == 2)
	{
		if (ft_bfactor(p->right) < 0)
			p->right = ft_rotateright(p->right);
		return (ft_rotateleft(p));
	}
	if (ft_bfactor(p) == -2)
	{
		if (ft_bfactor(p->left) > 0)
			p->left = ft_rotateleft(p->left);
		return (ft_rotateright(p));
	}
	return (p);
}
