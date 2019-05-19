/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:19:47 by efouille          #+#    #+#             */
/*   Updated: 2019/01/13 01:57:19 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xatoi(const char *str, char *digits)
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
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i] && ft_index_of(digits, str[i] > -1)
			&& ((nbr <= 9223372036854775807ULL && negative == 1)
			|| (nbr <= 9223372036854775808ULL && negative == -1)))
		nbr = 16 * nbr + (long)ft_index_of(digits, str[i++]);
	if (nbr > 9223372036854775807ULL && negative == 1)
		return (-1);
	if (nbr > 9223372036854775808ULL && negative == -1)
		return (0);
	return ((int)negative * (int)nbr);
}
