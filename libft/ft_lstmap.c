/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:31:58 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/03 22:32:00 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = f(lst);
	if (list == NULL)
		return (NULL);
	if (lst->next)
	{
		list->next = ft_lstmap(lst->next, f);
		if (list->next == NULL)
		{
			free(list);
			return (NULL);
		}
	}
	return (list);
}
