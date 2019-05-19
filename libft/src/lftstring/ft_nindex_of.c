/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nindex_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:37:54 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/17 00:52:41 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gives the index of the first occurence of c in s
**
** input :	s	- the string to search in
**			c	- the character to search
**
** output :	(int) the index of first occurence of c in s
*/

int	ft_nindex_of(const char *s, char c, int max)
{
	return (ft_nindex_of_nth(s, c, 0, max));
}
