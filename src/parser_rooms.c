/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:06:29 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 21:45:40 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	parse_room(char *line, char **name, int *x, int *y)
{
	t_uint	i;
	t_uint	start;
	char	*tmp;

	i = 0;
	skip_spaces(line, &i);
	start = i;
	while (line[i] && line[i] != ' ')
		++i;
	*name = ft_strsub(line, start, i - start);
	skip_spaces(line, &i);
	start = i;
	while (line[i] && line[i] != ' ')
		++i;
	tmp = ft_strsub(line, start, i - start);
	*x = ft_atoi(tmp);
	free(tmp);
	skip_spaces(line, &i);
	start = i;
	while (line[i] && line[i] != ' ')
		++i;
	tmp = ft_strsub(line, start, i - start);
	*y = ft_atoi(tmp);
	free(tmp);
}

int			duplicate_rooms(t_graph *graph, char *name)
{
	size_t		i;

	i = 0;
	while (graph->rooms[i] && i < graph->nrooms)
	{
		if (!ft_strcmp(name, graph->rooms[i]))
			return (1);
		i++;
	}
	return (0);
}

int			ft_rooms(t_graph *graph, t_file *file, int command)
{
	char	*name;
	int		x;
	int		y;
	size_t	k;

	if (!file->line || !(*file->line))
		return (-1);
	k = 0;
	while (graph->rooms[k] && k < graph->nrooms - 1)
		++k;
	parse_room(file->line, &name, &x, &y);
	if (duplicate_rooms(graph, name))
	{
		free(name);
		graph->err_line = file->nline;
		return (err_room_duplicate);
	}
	graph->rooms[k] = name;
	if (command == lm_start || command == lm_start + lm_end)
		graph->start = k;
	if (command == lm_end || command == lm_start + lm_end)
		graph->end = k;
	return (1);
}
