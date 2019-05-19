/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:18:12 by efouille          #+#    #+#             */
/*   Updated: 2019/01/15 16:42:52 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static int	get_compatible_flags(char conv)
{
	int	cmp[128];

	cmp['c'] = F_MINUS;
	cmp['s'] = F_MINUS;
	cmp['p'] = F_ZERO | F_MINUS | F_PLUS | F_SPACE;
	cmp['d'] = F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['i'] = cmp['d'];
	cmp['o'] = F_HASH | F_ZERO | F_MINUS | F_PLUS;
	cmp['u'] = F_ZERO | F_MINUS | F_QUOTE;
	cmp['x'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE;
	cmp['X'] = cmp['x'];
	cmp['f'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['F'] = cmp['f'];
	cmp['b'] = F_HASH | F_ZERO | F_MINUS | F_PLUS | F_SPACE | F_QUOTE;
	cmp['B'] = cmp['b'];
	cmp['n'] = F_NONE;
	cmp['%'] = F_ZERO | F_MINUS;
	cmp['k'] = F_NONE;
	return (cmp[(int)conv]);
}

static void	convert_big_csdou(t_fmt *fmt)
{
	if (fmt->conversion == 'C'
			|| fmt->conversion == 'S'
			|| fmt->conversion == 'D'
			|| fmt->conversion == 'O'
			|| fmt->conversion == 'U')
	{
		fmt->conversion += 0x20;
		fmt->modifiers = 0x0;
		ft_setbit((t_imax*)&(fmt->modifiers), I_L);
	}
}

void		sanitize_format(t_fmt *fmt)
{
	while (fmt)
	{
		if (known_conversion(fmt->conversion))
		{
			convert_big_csdou(fmt);
			fmt->flags &= get_compatible_flags(fmt->conversion);
			if (fmt->precision > 0 && fmt->conversion != 'f'
					&& fmt->conversion != 'F' && fmt->conversion != '%')
				ft_unsetbit((t_imax*)&(fmt->flags), I_ZERO);
			if (fmt->conversion == 'p')
				ft_setbit((t_imax*)&(fmt->modifiers), I_J);
			if (fmt->precision == -1
				&& (fmt->conversion == 'f' || fmt->conversion == 'F'))
				fmt->precision = 6;
		}
		fmt = fmt->next;
	}
}
