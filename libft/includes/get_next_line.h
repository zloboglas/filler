/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:40:33 by dlabadie          #+#    #+#             */
/*   Updated: 2019/04/08 16:42:16 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 1
# define READ(log, buf) (log <= -1) || (log == 0 && buf[0] == '\0')
# define RET(log) (log <= -1) ? -1 : 0

typedef struct		s_session
{
	int				fd;
	char			*buf2conserve;
}					t_ss;

#endif
