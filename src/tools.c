/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:10:04 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 21:15:33 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		ft_isint(char *s, int start, int end)
{
	int		i;
	t_imax	n;

	i = start;
	if (!s || !*s)
		return (0);
	if (s[i] == '-')
	{
		i++;
		if (i > end)
			return (0);
	}
	while (i <= end)
	{
		if (!ft_isdigit((int)s[i]))
			return (0);
		i++;
	}
	n = ft_atoimax(s + start);
	if (n != (int)n)
		return (0);
	return (1);
}

void	skip_spaces(char *s, t_uint *i)
{
	while (s && s[*i] && s[*i] == ' ')
		++(*i);
}
