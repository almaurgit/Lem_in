/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:34:15 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/13 08:21:40 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	print_queue(t_queue *q)
{
	t_element	*el;

	el = q->front;
	while (el)
	{
		ft_printf("[%d] -> ", el->room);
		el = el->next;
	}
	ft_printf("\n");
	if (q->front)
	{
		ft_printf("First element : %d, ", q->front->room);
		ft_printf("last element : %d\n", q->back->room);
	}
}

void	delete_queue(t_queue **q)
{
	if (!q || !(*q))
		return ;
	while ((*q)->front)
		pop_queue(*q);
	free(*q);
	*q = NULL;
}

int		room_in_queue(t_queue *q, int room)
{
	t_element	*tmp;

	tmp = q->front;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (tmp->room == room)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
