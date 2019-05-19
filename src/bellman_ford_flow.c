/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford_flow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 04:02:37 by efouille          #+#    #+#             */
/*   Updated: 2019/03/17 00:03:58 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"

void	bf_create_flow(t_graph *g)
{
	int		room;

	room = g->end;
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

int		bf_flow_through(int room, t_graph *g)
{
	size_t	i;

	i = 0;
	while (i < g->nrooms)
	{
		if (g->edk_flow[i][room] || g->edk_flow[room][i])
		{
			return (1);
		}
		++i;
	}
	return (0);
}

int		bf_upward_flow(t_graph *g, int curr_room, int next_room)
{
	if (g->flow_through[curr_room])
	{
		if (curr_room != g->start
			&& g->edk_flow[curr_room][g->bfs_parent[curr_room]])
			return (1);
		else if (g->edk_flow[next_room][curr_room])
			return (1);
		else
			return (0);
	}
	else
		return (1);
}
