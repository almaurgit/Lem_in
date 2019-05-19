/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:03:21 by efouille          #+#    #+#             */
/*   Updated: 2019/01/13 04:21:26 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <stdlib.h>

static void	init_printers(t_pfenv *env)
{
	env->printers['c'] = print_c;
	env->printers['s'] = print_s;
	env->printers['p'] = print_poub;
	env->printers['d'] = print_di;
	env->printers['i'] = print_di;
	env->printers['o'] = print_poub;
	env->printers['u'] = print_poub;
	env->printers['x'] = print_x;
	env->printers['X'] = print_x;
	env->printers['f'] = print_dbl;
	env->printers['F'] = print_dbl;
	env->printers['b'] = print_poub;
	env->printers['B'] = print_poub;
	env->printers['%'] = print_percent;
	env->printers['k'] = print_date;
}

static void	add_xtra(t_pfenv *env)
{
	int	k;

	k = 0;
	while (g_xtra_conv && g_xtra_prnt && g_xtra_conv[k] && g_xtra_prnt[k])
	{
		env->printers[(int)g_xtra_conv[k]] = g_xtra_prnt[k];
		++k;
	}
}

t_pfenv		*create_env(const char *f, t_fmt *fs, t_str *out, va_list vl)
{
	t_pfenv	*env;

	if (!(env = (t_pfenv*)malloc(sizeof(t_pfenv))))
		return (NULL);
	bzero(env->printers, 128);
	init_printers(env);
	add_xtra(env);
	env->format = f;
	env->formats = fs;
	env->cur_fmt = fs;
	env->output = out;
	va_copy(env->vl, vl);
	env->stop = 0;
	return (env);
}

void		clear_env(t_pfenv **env)
{
	if (env)
	{
		if (*env)
		{
			free(*env);
			*env = NULL;
		}
	}
}
