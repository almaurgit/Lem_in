/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:21:15 by efouille          #+#    #+#             */
/*   Updated: 2019/03/14 04:14:47 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ap, size_t size, size_t new_size)
{
	void	*tmp;

	if (!ap)
		return (ft_memalloc(new_size));
	else
	{
		if (!(tmp = ft_memalloc(new_size)))
			return (NULL);
		ft_memmove(tmp, ap, size);
		free(ap);
		return (tmp);
	}
}
