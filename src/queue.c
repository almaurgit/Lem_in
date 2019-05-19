/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 04:12:51 by efouille          #+#    #+#             */
/*   Updated: 2019/03/13 07:49:51 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include "libft.h"
#include <stdlib.h>

t_queue	*new_queue(void)
{
	t_queue	*new;

	if (!(new = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	new->min = 100000;
	return (new);
}

int		append_queue(t_queue *q, int room)
{
	t_element	*new;

	if (!q)
		return (0);
	if (!(new = ft_memalloc(sizeof(t_element))))
		return (0);
	new->room = room;
	new->next = NULL;
	if (!q->back)
	{
		new->prev = NULL;
		q->back = new;
		q->front = new;
	}
	else
	{
		q->back->next = new;
		new->prev = q->back;
		q->back = new;
	}
	return (1);
}

int		prepend_queue(t_queue *q, int room)
{
	t_element	*new;

	if (!q)
		return (0);
	if (!(new = ft_memalloc(sizeof(t_element))))
		return (0);
	new->room = room;
	new->next = NULL;
	if (!q->front)
	{
		new->next = NULL;
		q->back = new;
		q->front = new;
	}
	else
	{
		q->front->prev = new;
		new->next = q->front;
		q->front = new;
	}
	return (1);
}

int		pop_queue(t_queue *q)
{
	int			room;
	t_element	*tmp;

	if (!q)
		return (-1);
	if (!q->front)
		return (-1);
	room = q->front->room;
	if (!q->front->next)
	{
		free(q->front);
		q->front = NULL;
		q->back = NULL;
	}
	else
	{
		tmp = q->front;
		q->front = q->front->next;
		q->front->prev = NULL;
		free(tmp);
	}
	return (room);
}

int		popback_queue(t_queue *q)
{
	int			room;
	t_element	*tmp;

	if (!q)
		return (-1);
	if (!q->back)
		return (-1);
	room = q->back->room;
	if (!q->back->prev)
	{
		free(q->back);
		q->front = NULL;
		q->back = NULL;
	}
	else
	{
		tmp = q->back;
		q->back = q->back->prev;
		q->back->next = NULL;
		free(tmp);
	}
	return (room);
}
