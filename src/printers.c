/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 01:25:09 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 19:27:18 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include "libft.h"

static int	valid_path_check(t_graph *g, int *path, int npath)
{
	int	i;

	i = 0;
	while (i < npath - 1)
	{
		if (!g->matrix[path[i]][path[i + 1]])
		{
			return (0);
		}
		++i;
	}
	return (1);
}

void		print_paths(t_graph *g)
{
	size_t	i;
	int		j;

	ft_printf("\n%zu PATHS\n", g->npaths);
	i = -1;
	while (++i < g->npaths)
	{
		ft_printf("Path %zu : ", i + 1);
		j = 0;
		while (j < g->paths_size[i])
		{
			ft_printf("%s ", g->rooms[g->paths[i][j]]);
			++j;
		}
		if (valid_path_check(g, g->paths[i], g->paths_size[i]))
			ft_printf("%sVALID PATH%s", SH_GREEN, SH_DEFAULT);
		else
			ft_printf("%sINVALID PATH%s", SH_RED, SH_DEFAULT);
		ft_printf("\n");
	}
}
