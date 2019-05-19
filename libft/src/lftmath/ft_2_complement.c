/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_complement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/13 01:47:45 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_imax	ft_2_complement(t_imax n)
{
	size_t	k;

	k = 0;
	while (k < sizeof(n) * 8)
	{
		if (ft_getbit(n, k))
			ft_unsetbit(&n, k);
		else
			ft_setbit(&n, k);
		++k;
	}
	return (n + 1);
}
