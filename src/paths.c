/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:14:27 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 16:52:14 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static void	create_size_paths(t_graph *g, int current, int *size_paths, int np)
{
	int		size;
	int		room;

	size = 1;
	room = current;
	while (room != g->start)
	{
		g->visited[room] = 2;
		if (g->bfs_parent[room] != -1)
			room = g->bfs_parent[room];
		++size;
	}
	size_paths[np] = size;
}

static int	end_get_path_count(t_graph *g, int curr, int *size_paths, int np)
{
	if (curr == g->end)
	{
		create_size_paths(g, g->bfs_parent[curr], size_paths, np);
		reinit_visited(g);
		ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
	}
	else
		return (0);
	return (1);
}

int			get_path_count(t_graph *g, int *size_paths, int npath)
{
	int		curr_room;
	int		i;

	curr_room = g->start;
	while (curr_room != g->end)
	{
		i = 0;
		while ((size_t)i < g->nrooms)
		{
			if (g->edk_flow[curr_room][i] == 1 && !g->visited[i])
			{
				g->bfs_parent[i] = curr_room;
				curr_room = i;
				break ;
			}
			++i;
		}
		if ((size_t)i == g->nrooms)
			return (0);
	}
	return (end_get_path_count(g, curr_room, size_paths, npath));
}
