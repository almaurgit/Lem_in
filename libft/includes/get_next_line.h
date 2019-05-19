/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:10:17 by efouille          #+#    #+#             */
/*   Updated: 2019/03/17 00:46:33 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 100

enum			e_ret {ok = 1, done = 0, fail = -1};

typedef struct	s_gnlfile
{
	int			fd;
	char		**line;
}				t_gnlfile;

int				get_next(int fd, char **line, char sep);
int				get_next_line(int fd, char **line);

#endif
