/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_in_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:19:10 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/16 03:34:21 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	*copy_tab_int(int *model, int size)
{
	int	*copy;
	int	i;

	if (size <= 0)
		return (NULL);
	i = 0;
	if (!(copy = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		copy[i] = model[i];
		++i;
	}
	return (copy);
}

int			get_argmin(int *tab, int size)
{
	int	index_of_minimum;
	int	i;

	i = 0;
	index_of_minimum = 0;
	if (!tab || size <= 0)
		return (-1);
	while (i < size)
	{
		if (tab[i] < tab[index_of_minimum])
			index_of_minimum = i;
		++i;
	}
	return (index_of_minimum);
}

int			get_argmax(int *tab, int size)
{
	int		index_of_maximum;
	int		i;

	i = 0;
	index_of_maximum = 0;
	if (!tab || size <= 0)
		return (-1);
	while (i < size)
	{
		if (tab[i] > tab[index_of_maximum])
			index_of_maximum = i;
		++i;
	}
	return (index_of_maximum);
}

static int	get_path_for_each_ant(t_graph *g)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < g->npaths)
	{
		k = 0;
		while (k < g->nants_paths[i])
		{
			g->ants_paths[j] = i;
			++j;
			++k;
		}
		++i;
	}
	return (1);
}

int			nants_paths(t_graph *g)
{
	int	*weigth_paths;
	int	i;
	int	n;

	n = g->nants;
	if (!(g->nants_paths = (int *)ft_memalloc(sizeof(int) * g->npaths)))
		return (err_malloc);
	if (!(weigth_paths = copy_tab_int(g->paths_size, g->npaths)))
		return (err_malloc);
	while (n)
	{
		i = get_argmin(weigth_paths, g->npaths);
		++(weigth_paths[i]);
		++((g->nants_paths)[i]);
		--n;
	}
	get_path_for_each_ant(g);
	free(weigth_paths);
	return (1);
}
