/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 06:19:58 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 21:46:03 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include <stdlib.h>

void		free_file(t_file **f)
{
	if (f && *f)
	{
		if ((*f)->next)
			free_file(&((*f)->next));
		free((*f)->line);
		free(*f);
		*f = NULL;
	}
}

void		free_paths(t_graph *g)
{
	size_t	i;

	i = 0;
	while (i < g->npaths)
	{
		free(g->paths[i]);
		++i;
	}
	g->npaths = 0;
}

void		free_edk(t_graph *g)
{
	size_t	i;

	i = 0;
	while (i < g->nrooms)
	{
		free(g->edk_flow[i]);
		free(g->edk_final[i]);
		++i;
	}
	free(g->edk_flow);
	free(g->edk_final);
}

static void	part_2(t_graph *g)
{
	free(g->bfs_parent);
	free(g->visited);
	free(g->flow_through);
	free(g->nants_paths);
	free(g->ants_paths);
	free(g->dist);
}

void		free_graph(t_graph *g)
{
	size_t	i;

	free(g->paths_size);
	free(g->ants_rooms);
	i = 0;
	while (i < g->nrooms)
	{
		free(g->rooms[i]);
		free(g->matrix[i]);
		++i;
	}
	i = 0;
	while (i < g->npaths)
	{
		free(g->paths[i]);
		++i;
	}
	free(g->rooms);
	free(g->matrix);
	free(g->paths);
	part_2(g);
}
