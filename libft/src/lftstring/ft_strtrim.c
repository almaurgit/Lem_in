/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:59:56 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/12 17:06:09 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_blank_str(const char *s)
{
	int	k;

	k = 0;
	while (s[k])
	{
		if (!ft_isblankspace(s[k]))
			return (0);
		k++;
	}
	return (1);
}

char		*ft_strtrim(const char *s)
{
	int	k1;
	int	k2;

	if (!s)
		return (NULL);
	if (is_blank_str(s) && ft_strlen(s) > 0)
		return (ft_strdup(""));
	k1 = 0;
	k2 = ft_strlen(s) - 1;
	while (ft_isblankspace(s[k1]))
		k1++;
	while (ft_isblankspace(s[k2]))
		k2--;
	return (ft_strsub(s, k1, k2 - k1 + 1));
}
