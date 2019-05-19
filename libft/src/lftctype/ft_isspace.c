/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 00:59:15 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/15 03:42:12 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check whether c is a space or not
**
** input :	c	- the character to check
**
** output :	(int) 1 if c is a space, 0 if not
*/

int	ft_isspace(int c)
{
	return ((c == '\n') || (c == '\t') || (c == '\v')
			|| (c == ' ') || (c == '\f') || (c == '\r'));
}
