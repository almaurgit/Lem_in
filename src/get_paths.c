/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:49:39 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/13 20:04:55 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void		reinit_visited(t_graph *g)
{
	size_t i;

	i = 0;
	while (i < g->nrooms)
	{
		if (g->visited[i] == 1)
			g->visited[i] = 0;
		++i;
	}
}

static void	create_path_end(t_graph *g, int curr_room, int size)
{
	int	room;
	int	*path;

	path = ft_memalloc(sizeof(int) * (size + 1));
	path[size--] = g->end;
	room = curr_room;
	g->paths_size[g->npaths] = size + 2;
	while (size >= 0)
	{
		path[size] = room;
		if (g->bfs_parent[room] != -1)
			room = g->bfs_parent[room];
		--size;
	}
	g->paths[g->npaths] = path;
	++g->npaths;
}

static void	create_path(t_graph *g, int curr_room)
{
	int	size;
	int	room;

	size = 1;
	room = curr_room;
	g->edk_final[room][g->end] = 0;
	g->edk_final[g->end][room] = 0;
	while (room != g->start)
	{
		g->visited[room] = 2;
		g->edk_final[room][g->bfs_parent[room]] = 0;
		g->edk_final[g->bfs_parent[room]][room] = 0;
		if (g->bfs_parent[room] != -1)
			room = g->bfs_parent[room];
		++size;
	}
	create_path_end(g, curr_room, size);
}

static int	next_room(t_graph *g, int *curr_room)
{
	int	i;

	i = 0;
	while ((size_t)i < g->nrooms)
	{
		if (!g->visited[i] && g->edk_final[*curr_room][i] > 0)
		{
			g->bfs_parent[i] = *curr_room;
			*curr_room = i;
			break ;
		}
		++i;
	}
	if ((size_t)i == g->nrooms)
		return (0);
	return (1);
}

int			get_path(t_graph *g)
{
	int	curr_room;

	curr_room = g->start;
	while (curr_room != g->end)
	{
		if (!next_room(g, &curr_room))
			return (0);
	}
	if (curr_room == g->end)
	{
		create_path(g, g->bfs_parent[curr_room]);
		reinit_visited(g);
		ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
	}
	else
		return (0);
	return (1);
}
