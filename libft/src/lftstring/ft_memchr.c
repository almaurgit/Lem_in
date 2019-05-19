/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 23:58:15 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/13 01:53:09 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (((t_uchar*)s)[k] == (t_uchar)c)
			return ((void*)&(((char*)s)[k]));
		k++;
	}
	return (NULL);
}
