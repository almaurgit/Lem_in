/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 05:22:06 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 01:53:39 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	next_room_in_path(t_graph *g, int room, int path)
{
	int i;

	i = 0;
	if (path == -1 || room == g->end)
		return (-1);
	while (i < g->paths_size[path] && g->paths[path][i] != room)
	{
		++i;
	}
	if (i >= g->paths_size[path])
		return (-1);
	return (g->paths[path][i + 1]);
}

static int	move_allowed(t_graph *g, int dst)
{
	int i;

	i = 0;
	if (dst < 0)
		return (0);
	if (dst == g->end)
		return (1);
	while (i < g->nants)
	{
		if (g->ants_rooms[i] == dst)
		{
			return (0);
		}
		++i;
	}
	return (1);
}

int			ants_at_end(t_graph *g)
{
	int i;

	i = 0;
	while (i < g->nants)
	{
		if (g->ants_rooms[i] != g->end)
			return (0);
		++i;
	}
	return (1);
}

void		move_ants(t_graph *g)
{
	int i;
	int next_room;
	int first_in_line;

	i = 0;
	first_in_line = 1;
	while (i < g->nants)
	{
		next_room = next_room_in_path(g, g->ants_rooms[i], g->ants_paths[i]);
		if (move_allowed(g, next_room) && (g->ants_rooms[i] != g->end))
		{
			g->ants_rooms[i] = next_room;
			if (first_in_line)
				first_in_line = 0;
			else
				ft_printf(" ");
			ft_printf("L%d-%s", i + 1, g->rooms[g->ants_rooms[i]]);
		}
		++i;
	}
	ft_printf("\n");
}
