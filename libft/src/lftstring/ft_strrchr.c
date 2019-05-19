/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:58:44 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/04 15:23:22 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret_c;
	int		k;

	ret_c = NULL;
	k = 0;
	while (s[k])
	{
		if (s[k] == (char)c)
			ret_c = (char*)&(s[k]);
		k++;
	}
	if (s[k] == (char)c)
		ret_c = (char*)&(s[k]);
	return (ret_c);
}
