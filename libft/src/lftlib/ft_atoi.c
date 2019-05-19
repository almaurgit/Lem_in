/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:35:11 by Edgar             #+#    #+#             */
/*   Updated: 2019/01/13 01:57:08 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	t_ull	nbr;
	long	negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9'
			&& ((nbr <= 9223372036854775807ULL && negative == 1)
			|| (nbr <= 9223372036854775808ULL && negative == -1)))
		nbr = 10 * nbr + (long)str[i++] - '0';
	if (nbr > 9223372036854775807ULL && negative == 1)
		return (-1);
	if (nbr > 9223372036854775808ULL && negative == -1)
		return (0);
	return ((int)negative * (int)nbr);
}
