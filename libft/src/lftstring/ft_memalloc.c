/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 16:54:34 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/13 01:19:32 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	k;

	ret = malloc(size * sizeof(char));
	if (!ret)
		return (NULL);
	k = 0;
	while (k < size)
		((char*)ret)[k++] = 0;
	return (ret);
}
