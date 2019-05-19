/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 05:45:03 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 17:15:55 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include "libft.h"

int		add_line(t_file **file, char *line)
{
	t_file *tmp;

	if (!line)
		return (1);
	tmp = *file;
	if (!*file)
	{
		if (!(*file = malloc(sizeof(t_file))))
			return (0);
		(*file)->line = line;
		(*file)->nline = 1;
		(*file)->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = malloc(sizeof(t_file))))
			return (0);
		tmp->next->line = line;
		tmp->next->nline = tmp->nline + 1;
		tmp->next->next = NULL;
	}
	return (1);
}

void	show_file(t_graph *graph, t_file *file)
{
	int		i;

	i = 1;
	if (graph->err_line == 0)
	{
		while (file)
		{
			ft_putendl(file->line);
			file = file->next;
		}
	}
	else
	{
		while (file && i < graph->err_line)
		{
			ft_putendl(file->line);
			file = file->next;
			i++;
		}
	}
}
