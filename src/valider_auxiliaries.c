/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valider_auxiliaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 05:33:51 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 03:46:39 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lm_types.h"
#include "libft.h"

static t_commands	*commands(void)
{
	static t_commands	cmds[3];

	cmds[0] = (t_commands){"start", lm_start};
	cmds[1] = (t_commands){"end", lm_end};
	cmds[2] = (t_commands){"", -1};
	return (cmds);
}

int					ft_iscommentary(char *s)
{
	if (!s || !*s)
		return (0);
	else if (s[0] == '#' && s[1] != '#')
		return (1);
	else
		return (0);
}

int					ft_iscommand(char *s, int command)
{
	int i;
	int	curr_com;

	i = 0;
	if (!s || !*s)
		return (0);
	else if (s[0] == '#' && s[1] && s[1] == '#')
	{
		while (ft_strcmp("", commands()[i].command))
		{
			if (!ft_strcmp(commands()[i].command, s + 2))
			{
				curr_com = commands()[i].ncommand;
				if ((command == lm_start && curr_com == lm_end)
					|| (command == lm_end && curr_com == lm_start))
					return (lm_start + lm_end);
				else
					return (curr_com);
			}
			i++;
		}
		if (!ft_strcmp("", commands()[i].command))
			return (command == lm_start || command == lm_end ? command : -1);
	}
	return (0);
}
