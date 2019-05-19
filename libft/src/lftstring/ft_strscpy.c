/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:53:50 by efouille          #+#    #+#             */
/*   Updated: 2018/05/18 14:18:13 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strscpy(char *dst, const char *src, int s)
{
	int	k;

	k = 0;
	if (s == -1)
		ft_strclr(dst);
	while (src[k + s])
	{
		dst[k] = src[k + s];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}
