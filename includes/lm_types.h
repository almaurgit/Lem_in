/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:04:09 by efouille          #+#    #+#             */
/*   Updated: 2019/03/16 20:37:11 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LM_TYPES_H
# define LM_TYPES_H

# include <string.h>

# define VERBOSE 0x1
# define NBLINES 0x2
# define PATHS 0x4

/*
** pour le tableau statique contenant les commandes
*/

typedef struct	s_commands
{
	char	*command;
	int		ncommand;
}				t_commands;

typedef struct	s_error
{
	int		err;
	char	*str_err;
}				t_error;

/*
** pour stocker (dans une liste) chaque ligne au fur et a mesure
*/

typedef struct	s_file
{
	char			*line;
	int				nline;
	struct s_file	*next;
}				t_file;

typedef struct	s_element
{
	int					room;
	int					dist;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct	s_queue
{
	int			min;
	t_element	*front;
	t_element	*back;
}				t_queue;

/*
** structure de stockage du graphe et de ses infos
**
**	nants			nombre de fourmis
**	nrooms			nombre de rooms
**	rooms			tableau de str des noms de rooms
**
**	matrix			tableau des liens entre rooms
**	edk_flow		matrice de flow provisoire
**	edk_final		matrice de flow finale
**
**	flow_through	tableau de capacité actuelle d'une room
**	dist			tableau contenant la distance actuelle a start d'une room
**	visited			tableau indiquant si une room est deja visitee
**	bfs_parent		tableau contenant le parent d'une room en creant un chemin
**
**	paths			tableau contenant les différents chemins de start à end
**	npaths			nombre de chemins
**	paths_size		tableau contenant la taille de chaque chemin
**
**	ants_rooms		index de la room de la i_eme fourmi
**	nants_paths		nombre de fourmis par chemin
**	ants_paths		index du chemin que chaque fourmi emprunte
**
**	start			index of start in rooms
**	end:			index of end in rooms
**
**	err_line		numero de ligne comportant une erreur
*/

typedef struct	s_graph
{
	int		nants;
	size_t	nrooms;
	char	**rooms;
	char	**matrix;
	char	**edk_flow;
	char	**edk_final;
	int		*flow_through;
	int		*dist;
	int		*visited;
	int		*bfs_parent;
	int		**paths;
	size_t	npaths;
	int		*paths_size;
	int		*ants_rooms;
	int		*nants_paths;
	int		*ants_paths;
	int		start;
	int		end;
	int		err_line;
}				t_graph;

enum			e_commands
{
	lm_start = 1,
	lm_end
};

enum			e_lerrors
{
	err_link_name = -16,
	err_link_missing,
	err_link_duplicate,
	err_link_noroom,
	err_link_nolink,
	err_ants,
	err_room_name,
	err_room_coord,
	err_room_ncoord,
	err_room_space,
	err_room_duplicate,
	err_room_startend,
	err_no_path,
	err_empty_file,
	err_malloc,
	err_unk,
};

#endif
