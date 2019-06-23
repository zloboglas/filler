/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:40:20 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/03 11:55:45 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static void			*ft_newss(const int fd)
{
	t_ss		*session;

	session = (t_ss*)malloc(sizeof(t_ss));
	session->fd = fd;
	session->buf2conserve = ft_strnew(0);
	return (session);
}

static int			ft_cmp(void *fd, void *d2)
{
	if (*(int*)fd < ((t_ss*)d2)->fd)
		return (-1);
	else if (*(int*)fd > ((t_ss*)d2)->fd)
		return (1);
	else
		return (0);
}

static t_tree		*ft_findss(t_tree **p, const int fd)
{
	t_ss		*session;
	t_tree		*sestree;

	if (*p == NULL)
	{
		session = ft_newss(fd);
		*p = ft_newavltree(session);
		sestree = *p;
	}
	else
	{
		sestree = ft_search(*p, (void*)&fd, &ft_cmp);
		if (sestree == NULL)
		{
			session = ft_newss(fd);
			sestree = ft_newavltree(session);
			*p = ft_insert(*p, sestree, (void*)&fd, &ft_cmp);
		}
	}
	return (sestree);
}

static int			ft_read(t_ss *session, char **line)
{
	int			readlog;
	size_t		rest;
	char		buf[BUFF_SIZE + 1];

	readlog = BUFF_SIZE;
	while ((rest = ft_strcfind(session->buf2conserve, '\n')) == \
(size_t)-1 && readlog == BUFF_SIZE)
	{
		readlog = (int)read(session->fd, &buf, BUFF_SIZE);
		if (READ(readlog, session->buf2conserve))
			return (RET(readlog));
		buf[readlog] = '\0';
		ft_overcat(&session->buf2conserve, buf);
	}
	if (rest != (size_t)-1)
	{
		ft_cpfirstn(line, session->buf2conserve, rest);
		ft_rmfirstn(&session->buf2conserve, rest);
		return (1);
	}
	*line = session->buf2conserve;
	session->buf2conserve = ft_strnew(0);
	return (1);
}

int					ft_get_next_line(const int fd, char **line)
{
	int					retlog;
	static t_tree		*p;
	t_tree				*sestree;

	if (line == NULL)
		return (-1);
	sestree = ft_findss(&p, fd);
	if (*line != NULL)
		*line = NULL;
	retlog = ft_read((t_ss*)sestree->data, line);
	if (retlog == 0)
	{
		free(((t_ss*)sestree->data)->buf2conserve);
		p = ft_remove(p, sestree->data, &ft_cmp);
	}
	return (retlog);
}
