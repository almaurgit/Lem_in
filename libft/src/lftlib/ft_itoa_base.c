/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:26:35 by efouille          #+#    #+#             */
/*   Updated: 2019/01/13 01:50:29 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(t_imax n, const t_uint b, const int caps)
{
	char	*ret;
	int		len;
	int		k;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_log(n, b);
	ret = (char*)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	k = len;
	while (n > 0)
	{
		ret[--k] = caps ? BASE_CAPS[n % b] : BASE[n % b];
		n /= b;
	}
	ret[len] = '\0';
	return (ret);
}
