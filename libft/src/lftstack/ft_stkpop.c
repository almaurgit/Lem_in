/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:33:08 by efouille          #+#    #+#             */
/*   Updated: 2018/11/20 05:22:10 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stkpop(t_stack *stk)
{
	t_stack	*prev;

	prev = NULL;
	if (!stk)
		return (NULL);
	while (stk->next)
	{
		prev = stk;
		stk = stk->next;
	}
	if (prev)
		prev->next = NULL;
	return (stk);
}
