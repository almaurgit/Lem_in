/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:53:28 by efouille          #+#    #+#             */
/*   Updated: 2019/01/12 01:01:06 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strappendchr(char **s, const char c)
{
	char	*ret;
	size_t	k;

	k = ft_strlen(*s);
	if (!(ret = (char*)malloc((k + 2) * sizeof(char))))
		return (NULL);
	ft_strcpy(ret, *s);
	ret[k] = c;
	ret[k + 1] = '\0';
	free(*s);
	*s = ret;
	return (*s);
}
