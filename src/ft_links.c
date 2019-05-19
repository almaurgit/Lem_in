/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:56:06 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/17 01:46:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	existing_firstroom(t_graph *graph, char *line, int i_sep, int *x)
{
	size_t	i;

	i = 0;
	while (i < graph->nrooms)
	{
		if (!ft_strncmp(graph->rooms[i], line, i_sep)
			&& ft_strlen(graph->rooms[i]) == (size_t)i_sep)
		{
			*x = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	existing_secondroom(t_graph *graph, char *line, int i_sep, int *y)
{
	size_t	i;

	i = 0;
	while (i < graph->nrooms)
	{
		if (!ft_strcmp(graph->rooms[i], line + i_sep + 1))
		{
			*y = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	existing_rooms(t_graph *graph, char *line, int *x, int *y)
{
	int		i_sep;

	i_sep = 0;
	while (line[i_sep] && line[i_sep] != '-')
		i_sep++;
	if (!existing_firstroom(graph, line, i_sep, x)
		|| !existing_secondroom(graph, line, i_sep, y))
		return (0);
	return (1);
}

int			ft_links(t_graph *graph, t_file *file)
{
	int		x;
	int		y;

	if (!file->line || !(*(file->line)))
		return (err_unk);
	if (!existing_rooms(graph, file->line, &x, &y))
	{
		graph->err_line = file->nline;
		return (err_link_noroom);
	}
	if (x != y)
	{
		graph->matrix[x][y] = 1;
		graph->matrix[y][x] = 1;
	}
	else
		return (err_link_duplicate);
	return (1);
}
