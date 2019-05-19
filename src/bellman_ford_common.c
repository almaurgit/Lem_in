/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford_common.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 04:22:48 by efouille          #+#    #+#             */
/*   Updated: 2019/03/12 04:25:14 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_setdist(t_graph *g)
{
	size_t i;

	i = 0;
	while (i < g->nrooms)
	{
		g->dist[i] = 100000;
		++i;
	}
}

void	reinit_capacity(t_graph *g)
{
	size_t		i;

	i = 0;
	while (i < g->nrooms)
	{
		if (g->flow_through[i] == 1)
		{
			if (!bf_flow_through(i, g))
				g->flow_through[i] = 0;
		}
		++i;
	}
}
