/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:57:49 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/04 15:23:31 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	while (src[k] && k < len)
	{
		dst[k] = src[k];
		k++;
	}
	while (k < len)
		dst[k++] = '\0';
	return (dst);
}
