/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 22:37:49 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/04 15:29:36 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	nlen;
	size_t	k;
	size_t	l;

	nlen = ft_strlen(n);
	if (nlen == 0)
		return ((char*)h);
	k = 0;
	while (h[k])
	{
		l = 0;
		while (((l <= nlen && n[l] == h[k + l])
			|| n[l] == '\0') && (k + l) <= len)
		{
			if (n[l] == '\0')
				return ((char*)&(h[k]));
			l++;
		}
		k++;
	}
	return (NULL);
}
