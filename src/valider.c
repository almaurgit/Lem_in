/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:19:02 by efouille          #+#    #+#             */
/*   Updated: 2019/03/17 00:39:32 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int	valid_nants(char *s)
{
	t_imax	nants;

	if (!s)
		return (err_unk);
	else if (!*s)
		return (err_ants);
	nants = ft_atoimax(s);
	if (nants != (int)nants)
		return (err_ants);
	while (*s)
	{
		if (!ft_isdigit((int)*(s++)))
			return (err_ants);
	}
	return (1);
}

int	valid_name(char *s, int imax)
{
	int	i;

	i = 0;
	if (!s || !*s || s[0] == 'L' || s[0] == '#')
		return (0);
	while (i < imax)
	{
		if (s[i] <= 32 || s[i] >= 127 || s[i] == '-')
			return (0);
		++i;
	}
	return (1);
}

int	valid_room(char *line, int i, int j)
{
	while (line[i] && line[i] != ' ')
		++i;
	if (!line[i])
		return (err_room_coord);
	else if (!valid_name(line, i))
		return (err_room_name);
	j = ++i;
	while (line[i] && line[i] != ' ')
		++i;
	if (!line[i])
		return (err_room_coord);
	else if (!ft_isint(line, j, i > j ? i - 1 : i))
		return (err_room_ncoord);
	j = ++i;
	if (!line[i])
		return (err_room_coord);
	while (line[i] && line[i] != ' ')
		++i;
	if (line[i] == ' ')
		return (err_room_space);
	else if (!ft_isint(line, j, i > j ? i - 1 : i))
		return (err_room_ncoord);
	return (1);
}

int	valid_links(char *line)
{
	int		i_sep;
	int		j;

	i_sep = 0;
	while (line[i_sep] && line[i_sep] != '-'
			&& line[i_sep] > 32 && line[i_sep] < 127)
		++i_sep;
	if (line[i_sep] != '-')
		return (err_link_name);
	if (!line[i_sep] || !line[i_sep + 1])
		return (err_link_missing);
	j = i_sep + 1;
	while (line[j])
	{
		if (line[j] == '-' || line[j] <= 32 || line[j] >= 127)
		{
			return (err_link_name);
		}
		++j;
	}
	return (1);
}
