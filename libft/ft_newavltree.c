/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newavltree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:52:38 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/13 19:52:42 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree				*ft_newavltree(void *data)
{
	t_tree			*tree;

	tree = (t_tree*)malloc(sizeof(t_tree));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	tree->height = 1;
	return (tree);
}
