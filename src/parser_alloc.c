/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 05:38:05 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 21:43:27 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	malloc_flow(t_graph *g)
{
	size_t i;

	if (g->nrooms == 0)
		return (1);
	i = 0;
	if (!(g->edk_flow = ft_memalloc(sizeof(char *) * g->nrooms)))
		return (0);
	while (i < g->nrooms)
	{
		if (!(g->edk_flow[i] = ft_memalloc(sizeof(char) * g->nrooms)))
			return (0);
		++i;
	}
	i = 0;
	if (!(g->edk_final = ft_memalloc(sizeof(char *) * g->nrooms)))
		return (0);
	while (i < g->nrooms)
	{
		if (!(g->edk_final[i] = ft_memalloc(sizeof(char) * g->nrooms)))
			return (0);
		++i;
	}
	return (1);
}

static int	malloc_tabs(t_graph *g)
{
	if (g->nrooms == 0)
		return (1);
	if (!(g->paths = (int**)ft_memalloc(g->nrooms * sizeof(int*)))
		|| !(g->paths_size = (int*)ft_memalloc(g->nrooms * sizeof(int)))
		|| !(g->bfs_parent = (int*)malloc(g->nrooms * sizeof(int)))
		|| !(g->visited = (int *)ft_memalloc(g->nrooms * sizeof(int)))
		|| !(g->flow_through = (int *)ft_memalloc(g->nrooms * sizeof(int)))
		|| !(g->dist = (int *)ft_memalloc(g->nrooms * sizeof(int))))
		return (0);
	ft_setdist(g);
	ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
	return (1);
}

int			ft_malloc_graph(t_graph *g)
{
	size_t	i;

	i = 0;
	if (!(g->rooms = ft_memalloc(g->nrooms * sizeof(char*))))
		return (0);
	if (!(g->matrix = (char**)ft_memalloc(sizeof(char *) * g->nrooms)))
		return (0);
	while (i < g->nrooms)
	{
		if (!(g->matrix[i] = (char*)ft_memalloc(sizeof(char) * g->nrooms)))
			return (0);
		++i;
	}
	if (!malloc_flow(g))
		return (0);
	if (!malloc_tabs(g))
		return (0);
	return (1);
}
