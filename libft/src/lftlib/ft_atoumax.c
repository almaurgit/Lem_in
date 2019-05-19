/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoumax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:56:36 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/13 12:57:21 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_umax	ft_atoumax(const char *str)
{
	int		i;
	t_umax	nbr;
	int		negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = 10 * nbr + (t_imax)str[i++] - '0';
	return (negative * nbr);
}
