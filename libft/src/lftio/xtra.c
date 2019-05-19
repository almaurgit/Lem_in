/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:26:27 by efouille          #+#    #+#             */
/*   Updated: 2019/01/16 01:18:30 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

char		*g_xtra_conv = NULL;
t_printer	*g_xtra_prnt = NULL;

static int	add_conv(char c, int old_size)
{
	char	*tmp;

	if (!(tmp = ft_memalloc((old_size + 1) * sizeof(char))))
		return (0);
	tmp[--old_size] = c;
	while (--old_size >= 0)
	{
		tmp[old_size] = g_xtra_conv[old_size];
		--old_size;
	}
	free(g_xtra_conv);
	g_xtra_conv = tmp;
	return (1);
}

static int	add_printer(t_printer p, int old_size)
{
	t_printer	*tmp;

	if (!(tmp = ft_memalloc((old_size + 1) * sizeof(t_printer))))
		return (0);
	tmp[--old_size] = p;
	while (--old_size >= 0)
	{
		tmp[old_size] = g_xtra_prnt[old_size];
		--old_size;
	}
	free(g_xtra_prnt);
	g_xtra_prnt = tmp;
	return (1);
}

int			init_xtra(void)
{
	g_xtra_conv = ft_memalloc(sizeof(char));
	g_xtra_prnt = ft_memalloc(sizeof(t_printer));
	if (!g_xtra_conv || !g_xtra_prnt)
	{
		free(g_xtra_conv);
		free(g_xtra_prnt);
		return (0);
	}
	return (1);
}

void		clean_xtra(void)
{
	if (g_xtra_conv)
	{
		free(g_xtra_conv);
		g_xtra_conv = NULL;
	}
	if (g_xtra_prnt)
	{
		free(g_xtra_prnt);
		g_xtra_prnt = NULL;
	}
}

int			improve_ftprintf(char c, t_printer p)
{
	int	c_size;
	int	p_size;

	c_size = 0;
	if (!g_xtra_conv || !g_xtra_prnt)
		return (0);
	while (g_xtra_conv[c_size])
		c_size++;
	c_size++;
	p_size = 0;
	while (g_xtra_prnt[p_size])
		p_size++;
	p_size++;
	if (!add_conv(c, c_size) || !add_printer(p, p_size))
		return (0);
	return (1);
}
