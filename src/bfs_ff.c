/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:49:39 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/16 23:54:37 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	create_flow(t_graph *g, int curr_room)
{
	int	room;

	room = curr_room;
	--(g->edk_flow[g->end][room]);
	++(g->edk_flow[room][g->end]);
	g->flow_through[room] = 1;
	while (room != g->start)
	{
		--(g->edk_flow[room][g->bfs_parent[room]]);
		++(g->edk_flow[g->bfs_parent[room]][room]);
		g->flow_through[room] = 1;
		if (g->bfs_parent[room] != -1)
			room = g->bfs_parent[room];
	}
}

static int	add_neighbors(t_graph *g, t_queue *q, int curr_room)
{
	int	i;

	i = 0;
	while ((size_t)i < g->nrooms)
	{
		if (g->matrix[curr_room][i] && !g->visited[i])
		{
			g->bfs_parent[i] = curr_room;
			if (i == g->end)
				return (g->end);
			append_queue(q, i);
			g->visited[i] = 1;
		}
		++i;
	}
	return (-1);
}

int			bfs(t_graph *g)
{
	t_queue *q;
	int		curr_room;

	if (!(q = new_queue()))
		return (0);
	append_queue(q, g->start);
	g->visited[g->start] = 1;
	while (q->front)
	{
		curr_room = pop_queue(q);
		if (add_neighbors(g, q, curr_room) == g->end)
		{
			create_flow(g, curr_room);
			ft_bzero(g->visited, g->nrooms * sizeof(int));
			ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
			delete_queue(&q);
			return (1);
		}
	}
	delete_queue(&q);
	return (0);
}
