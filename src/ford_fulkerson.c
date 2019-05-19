/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ford_fulkerson.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:52:04 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/16 22:24:46 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	count_lines(int *size_paths, int nants, int npath)
{
	int	i;

	i = 0;
	if (npath == 1 && size_paths[0] == 1)
		return (1);
	while (nants--)
	{
		i = get_argmin(size_paths, npath);
		++size_paths[i];
	}
	return (size_paths[i]);
}

static int	nb_line(t_graph *g, int max_flow)
{
	int		nb_lines;
	int		*size_paths;
	int		npath;

	npath = 0;
	size_paths = ft_memalloc(sizeof(int) * max_flow);
	while (npath < max_flow && get_path_count(g, size_paths, npath))
		++npath;
	nb_lines = count_lines(size_paths, g->nants, npath);
	free(size_paths);
	ft_bzero(g->visited, g->nrooms * sizeof(int));
	return (nb_lines);
}

static int	copy_matrix(char **dest, char **src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			dest[i][j] = src[i][j];
			++j;
		}
		++i;
	}
	return (1);
}

int			edk(t_graph *g)
{
	int	max_flow;
	int	nb_line1;
	int	nb_line2;

	max_flow = 1;
	nb_line1 = nb_line(g, max_flow);
	copy_matrix(g->edk_final, g->edk_flow, g->nrooms);
	while (bellman_ford_spfa(g) && max_flow < g->nants)
	{
		nb_line2 = nb_line(g, max_flow + 1);
		if (nb_line2 <= nb_line1)
		{
			++max_flow;
			nb_line1 = nb_line2;
			copy_matrix(g->edk_final, g->edk_flow, g->nrooms);
			continue ;
		}
		else
			break ;
	}
	return (max_flow);
}
