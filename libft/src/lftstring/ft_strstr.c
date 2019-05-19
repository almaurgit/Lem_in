/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 22:14:08 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/04 15:23:15 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	nlen;
	int	k;
	int	l;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char*)haystack);
	k = 0;
	while (haystack[k])
	{
		l = 0;
		while ((l <= nlen && needle[l] == haystack[k + l]) || needle[l] == '\0')
		{
			if (needle[l] == '\0')
				return ((char*)&(haystack[k]));
			l++;
		}
		k++;
	}
	return (NULL);
}
