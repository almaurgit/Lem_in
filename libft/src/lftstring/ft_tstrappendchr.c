/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrappendchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:16:53 by efouille          #+#    #+#             */
/*   Updated: 2019/01/14 21:33:45 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_str	*ft_tstrappendchr(t_str *s, const char c)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(s->len + 2)))
		return (NULL);
	ft_memcpy(tmp, s->str, s->len);
	tmp[s->len++] = c;
	tmp[s->len] = '\0';
	free(s->str);
	s->str = tmp;
	return (s);
}
