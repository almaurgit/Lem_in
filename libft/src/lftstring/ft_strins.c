/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/15 20:31:50 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strins(char **str, char c, int pos)
{
	char	*tmp;
	int		k;

	tmp = NULL;
	if (str && *str)
	{
		if (!(tmp = (char*)malloc((ft_strlen(*str) + 2) * sizeof(char))))
			return (NULL);
		k = 0;
		while (k < pos)
		{
			tmp[k] = (*str)[k];
			k++;
		}
		tmp[k++] = c;
		while ((*str)[k - 1])
		{
			tmp[k] = (*str)[k - 1];
			k++;
		}
		tmp[k] = '\0';
		free(*str);
		*str = tmp;
	}
	return (tmp);
}
