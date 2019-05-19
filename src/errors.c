/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:18:17 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/17 00:57:49 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static t_error	*errs(void)
{
	static	t_error	err[16];

	err[0] = (t_error){err_ants, ERR_ANTS};
	err[1] = (t_error){err_room_name, ERR_ROOM_NAME};
	err[2] = (t_error){err_room_coord, ERR_ROOM_COORD};
	err[3] = (t_error){err_room_ncoord, ERR_ROOM_NCOORD};
	err[4] = (t_error){err_room_space, ERR_ROOM_SPACE};
	err[5] = (t_error){err_room_duplicate, ERR_ROOM_DUPL};
	err[6] = (t_error){err_room_startend, ERR_ROOM_STARTEND};
	err[7] = (t_error){err_link_name, ERR_LINK_NAME};
	err[8] = (t_error){err_link_missing, ERR_ROOM_MSNG};
	err[9] = (t_error){err_link_noroom, ERR_LINK_NOROOM};
	err[10] = (t_error){err_link_duplicate, ERR_LINK_DUPL};
	err[11] = (t_error){err_link_nolink, ERR_LINK_NOLINK};
	err[12] = (t_error){err_empty_file, ERR_EMPTY_FILE};
	err[13] = (t_error){err_malloc, ERR_MALLOC};
	err[14] = (t_error){err_no_path, ERR_NO_PATH};
	err[15] = (t_error){err_unk, ERR_UNKNOWN};
	return (err);
}

int				ft_error(t_graph *g, int err, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	else if (flag == 3)
		return (0);
	while (errs()[i].err != err && errs()[i].err < -1)
		i++;
	if (err <= err_link_noroom && err >= err_link_name && flag != 1)
	{
		ft_dprintf(2, "\n%sFile reading stopped at line ", SH_YELLOW);
		ft_dprintf(2, "%d ", g->err_line);
		ft_dprintf(2, "for the following reason :\n");
		ft_dprintf(2, "%s%s\n", errs()[i].str_err, SH_DEFAULT);
	}
	else if (g->err_line)
		ft_dprintf(2, "ERROR\n%s (line %d)\n", errs()[i].str_err, g->err_line);
	else
		ft_dprintf(2, "ERROR\n%s\n", errs()[i].str_err, g->err_line);
	return (0);
}

int				get_current_line(t_file *file, int flag)
{
	if (!file)
		return (0);
	if (flag == 2)
		return (file->nline);
	else if (flag == 1)
	{
		while (file && file->next)
			file = file->next;
	}
	return (file->nline);
}
