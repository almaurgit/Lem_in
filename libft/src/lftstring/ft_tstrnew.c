/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:13:41 by efouille          #+#    #+#             */
/*   Updated: 2019/01/13 01:21:48 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_str	*ft_tstrnew(size_t size)
{
	t_str	*ret;
	char	*str;

	if (!(ret = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	if (!(str = ft_strnew(size)))
	{
		free(ret);
		return (NULL);
	}
	ret->str = str;
	ret->len = size;
	return (ret);
}
