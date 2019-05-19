/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:53:49 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/17 00:59:28 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "libft.h"

static int	fts_graph(t_graph *graph, t_file *file, int command)
{
	int	ret;

	ret = 1;
	if (valid_nants(file->line) > 0)
		ret = ft_ants(graph, file->line);
	else if (valid_room(file->line, 0, 0) > 0)
		ret = ft_rooms(graph, file, command);
	else if (valid_links(file->line) > 0)
	{
		if (graph->end == -1 || graph->start == -1)
			return (err_room_startend);
		ret = ft_links(graph, file);
	}
	return (ret);
}

static int	fts_validers(t_graph *graph, char *line, int *flag)
{
	int ret;

	ret = 0;
	if (*flag == 1)
	{
		ret = valid_nants(line);
		if (ret > 0)
			*flag = 2;
	}
	else if (*flag == 2)
	{
		ret = valid_room(line, 0, 0);
		if (ret > 0)
			++(graph->nrooms);
		else if (valid_links(line) == 1)
		{
			ret = 1;
			*flag = 3;
		}
	}
	if (*flag == 3)
	{
		ret = valid_links(line);
	}
	return (ret);
}

static int	treat_line(t_graph *graph, t_file *file, int *command)
{
	int ret;

	if (!(ft_iscommand(file->line, 0)))
	{
		if ((ret = fts_graph(graph, file, *command)) < 0)
		{
			graph->err_line = get_current_line(file, 2);
			return (ret);
		}
		*command = 0;
	}
	else
		*command = ft_iscommand(file->line, *command);
	return (1);
}

static int	parse_file(t_graph *graph, t_file *file, int err)
{
	int	command;
	int ret;

	command = 0;
	while (file)
	{
		if (!file->next && err)
			break ;
		if (ft_iscommentary(file->line))
		{
			file = file->next;
			continue ;
		}
		if ((ret = treat_line(graph, file, &command)) < 0)
			return (ret);
		file = file->next;
	}
	return (1);
}

int			parser(int fd, t_graph *graph, t_file **file)
{
	char	*line;
	int		flag;
	int		ret;
	int		ret2;

	line = NULL;
	flag = 1;
	ret = 0;
	ret2 = 0;
	while (ret >= 0 && get_next_line(fd, &line) > 0)
	{
		if (!add_line(file, line))
			return (err_malloc);
		if (ft_iscommentary(line) || ft_iscommand(line, 0))
			continue ;
		if ((ret = fts_validers(graph, line, &flag)) < 0)
			graph->err_line = get_current_line(*file, 1);
	}
	if (!ft_malloc_graph(graph))
		return (err_malloc);
	if (flag == 2 && ret > 0)
		return (err_link_nolink);
	if (ret > 0 || ret <= err_link_noroom)
		ret2 = parse_file(graph, *file, ret < 0 ? 1 : 0);
	return (ret2 < 0 ? ret2 : ret);
}
