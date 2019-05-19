/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblankspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:56:41 by Edgar             #+#    #+#             */
/*   Updated: 2018/04/15 03:42:17 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** check whether c is a blank space or not
**
** input :	c	- the character to check
**
** output :	(int) 1 if c is a blank space, 0 if not
*/

int	ft_isblankspace(int c)
{
	return ((c == '\n') || (c == '\t') || (c == ' '));
}
