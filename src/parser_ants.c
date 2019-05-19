/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:29:00 by efouille          #+#    #+#             */
/*   Updated: 2019/03/12 05:42:53 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include "libft.h"

int	ft_ants(t_graph *graph, char *line)
{
	graph->nants = ft_atoi(line);
	return (1);
}
