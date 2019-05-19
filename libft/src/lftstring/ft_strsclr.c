/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 12:40:50 by efouille          #+#    #+#             */
/*   Updated: 2018/08/02 12:47:46 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** same as strclr but from index s of str
**
** input :	s	- the index where clear starts
** 			n	- max size
**
** output :	none
*/

#include "libft.h"

void	ft_strsclr(char *str, int s, int n)
{
	if (str)
	{
		while (s < n)
		{
			str[s] = '\0';
			s++;
		}
	}
}
