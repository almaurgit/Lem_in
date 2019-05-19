/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:37:39 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/13 01:20:44 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		k;
	int		l;
	char	*rets;

	l = ft_strlen(str);
	rets = (char*)malloc((l + 1) * sizeof(char));
	if (!rets)
		return (NULL);
	k = 0;
	while (k < l + 1)
	{
		rets[k] = str[l - 1 - k];
		k++;
	}
	return (rets);
}
