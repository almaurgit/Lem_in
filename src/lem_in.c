/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:38:49 by efouille          #+#    #+#             */
/*   Updated: 2019/03/17 01:38:08 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	get_anted(t_graph *g, char options)
{
	int	i;

	if (!(g->ants_rooms = (int*)malloc(g->nants * sizeof(int)))
		|| !(g->ants_paths = (int*)malloc(g->nants * sizeof(int))))
		return (0);
	ft_memset(g->ants_paths, -1, sizeof(int) * g->nants);
	nants_paths(g);
	i = 0;
	while (i < g->nants)
	{
		g->ants_rooms[i] = g->start;
		++i;
	}
	i = 0;
	while (!ants_at_end(g))
	{
		if (options & NBLINES)
			ft_printf("%s{Step %d}%s ", SH_GREEN, i + 1, SH_DEFAULT);
		move_ants(g);
		++i;
	}
	if (options & NBLINES)
		ft_printf("%s%d lines%s\n", SH_GREEN, i, SH_DEFAULT);
	return (1);
}

static int	get_options(int ac, char **av)
{
	int		i;
	int		j;
	char	options;

	options = 0;
	if (ac == 1)
		return (0);
	i = 1;
	j = 0;
	while (i < ac && av[i][j] == '-')
	{
		++j;
		while (av[i][j])
		{
			options = av[i][j] == 'v' ? options | VERBOSE : options;
			options = av[i][j] == 'n' ? options | NBLINES : options;
			options = av[i][j] == 'p' ? options | PATHS : options;
			++j;
		}
		j = 0;
		++i;
	}
	return (options);
}

static int	solve_test(t_graph *g, char options)
{
	edk(g);
	ft_bzero(g->visited, g->nrooms * sizeof(int));
	ft_memset(g->bfs_parent, -1, g->nrooms * sizeof(int));
	while (get_path(g))
		;
	if (g && g->nants > 0)
		write(1, "\n", 1);
	if (!get_anted(g, options))
		return (0);
	if (options & PATHS)
		print_paths(g);
	return (1);
}

static int	check_parse(t_graph *g, t_file *f, int ret, char options)
{
	if (!f)
		return (ft_error(g, err_empty_file, options & VERBOSE ? 1 : 0));
	if (ret > err_link_noroom && ret < 0)
		return (ft_error(g, ret, options & VERBOSE ? 1 : 0));
	else if (ret >= err_link_name && ret <= err_link_noroom)
	{
		if (!bfs(g))
			return (ft_error(g, ret, options & VERBOSE ? 1 : 0));
		else
		{
			show_file(g, f);
			ft_error(g, ret, options & VERBOSE ? 2 : 3);
		}
	}
	else if (ret == 0)
		return (-1);
	else
	{
		if (!bfs(g))
			return (ft_error(g, err_no_path, options & VERBOSE ? 2 : 0));
		show_file(g, f);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_graph	g;
	t_file	*f;
	char	options;
	int		ret;

	ft_memset(&g, 0, sizeof(t_graph));
	g.start = -1;
	g.end = -1;
	f = NULL;
	options = get_options(ac, av);
	ret = parser(0, &g, &f);
	if (!check_parse(&g, f, ret, options))
		ret = -1;
	else
	{
		ret = 0;
		solve_test(&g, options);
	}
	free_file(&f);
	free_paths(&g);
	free_edk(&g);
	free_graph(&g);
	return (ret);
}
