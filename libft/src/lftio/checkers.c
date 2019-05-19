/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:41:53 by efouille          #+#    #+#             */
/*   Updated: 2019/01/15 15:53:24 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_const.h"
#include "libft.h"

int	known_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == 'F' || c == 'b' || c == 'B' || c == 'n' || c == '%'
			|| c == 'C' || c == 'S' || c == 'D' || c == 'O' || c == 'U'
			|| c == 'k')
	{
		return (1);
	}
	return (0);
}

int	valid_unknown_conversion(char c)
{
	if (ft_index_of(FLAGS, c) == -1 && ft_index_of(PRECISION, c) == -1
			&& ft_index_of(MODIFIERS, c) == -1)
	{
		return (1);
	}
	return (0);
}
