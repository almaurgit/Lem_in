/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford_spfa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 04:18:54 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 19:07:37 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	treat_room(t_graph *g, size_t curr_room, size_t j, t_queue *q)
{
	int		k;

	k = g->edk_flow[curr_room][j] == -1 ? -1 : 1;
	if (g->dist[curr_room] + k < g->dist[j])
	{
		g->dist[j] = g->dist[curr_room] + k;
		g->bfs_parent[j] = curr_room;
		if (!room_in_queue(q, j))
		{
			append_queue(q, j);
			if (g->dist[q->back->room] < g->dist[q->front->room])
			{
				popback_queue(q);
				prepend_queue(q, j);
			}
		}
	}
}

static int	end_bf_spfa(t_graph *g, t_queue *q)
{
	int	ret;

	if (g->dist[g->end] == 100000)
		ret = 0;
	else
	{
		bf_create_flow(g);
		ft_setdist(g);
		q->min = 100000;
		reinit_capacity(g);
		ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
		ret = 1;
	}
	delete_queue(&q);
	return (ret);
}

int			bellman_ford_spfa(t_graph *g)
{
	size_t	curr_room;
	size_t	j;
	t_queue *q;

	if (!(q = new_queue()))
		return (0);
	g->dist[g->start] = 0;
	append_queue(q, g->start);
	while (q->front)
	{
		curr_room = pop_queue(q);
		j = 0;
		while (j < g->nrooms)
		{
			if (g->matrix[curr_room][j] && g->edk_flow[curr_room][j] != 1
				&& bf_upward_flow(g, curr_room, j)
				&& curr_room != (size_t)g->end)
				treat_room(g, curr_room, j, q);
			++j;
		}
	}
	return (end_bf_spfa(g, q));
}
