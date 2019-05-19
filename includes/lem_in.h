/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:22:15 by amaurel           #+#    #+#             */
/*   Updated: 2019/03/17 01:44:39 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <string.h>
# include <unistd.h>

# include "lm_types.h"
# include "libft_types.h"

# define ERR_ANTS "Invalid number of ants : not a (positive) int"
# define ERR_ROOM_NAME "Invalid room declaration : invalid name"
# define ERR_ROOM_COORD "Invalid room declaration : missing coordinates"
# define ERR_ROOM_NCOORD "Invalid room declaration : invalid coordinates"
# define ERR_ROOM_SPACE "Invalid room declaration : space at end of line"
# define ERR_ROOM_DUPL "Invalid room decl. : room w/ identical name exists"
# define ERR_ROOM_STARTEND "Invalid room decl. : missing start or end"
# define ERR_LINK_NAME "Invalid link declaration : invalid room name"
# define ERR_ROOM_MSNG "Invalid link decl. : a link between two rooms needed"
# define ERR_LINK_NOROOM "Invalid link declaration : no room with such name"
# define ERR_LINK_DUPL "Invalid link decl. : a room is linked to itself"
# define ERR_LINK_NOLINK "Invalid link declaration : no links declared"
# define ERR_EMPTY_FILE "Empty file"
# define ERR_MALLOC "Malloc failure"
# define ERR_NO_PATH "Invalid file : no path from start to end"
# define ERR_UNKNOWN "Unknown error"

/*
** ants_in_paths.c
*/

int				get_argmin(int *tab, int size);
int				get_argmax(int *tab, int size);
int				nants_paths(t_graph *g);

/*
** bellman_ford_common.c
*/

void			ft_setdist(t_graph *g);
void			reinit_capacity(t_graph *g);

/*
** bellman_ford_flow.c
*/

void			bf_create_flow(t_graph *g);
int				bf_flow_through(int room, t_graph *g);
int				bf_upward_flow(t_graph *g, int curr_room, int next_room);

/*
** bf_queue.c
*/

void			print_queue(t_queue *q);
void			delete_queue(t_queue **q);
int				room_in_queue(t_queue *q, int room);

/*
** bellman_ford_spfa.c
*/

int				bellman_ford_spfa(t_graph *g);

/*
** bfs_ff.c
*/

int				bfs(t_graph *g);

/*
** cleanup.c
*/

void			free_file(t_file **f);
void			free_paths(t_graph *g);
void			free_edk(t_graph *g);
void			free_graph(t_graph *g);

/*
** errors.c
*/

int				ft_error(t_graph *graph, int err, int flag);
int				get_current_line(t_file *file, int line);

/*
** file.c
*/

int				add_line(t_file **file, char *line);
void			show_file(t_graph *graph, t_file *file);

/*
** ford_fulkerson.cc
*/

int				edk(t_graph *g);

/*
** ft_links.c
*/

int				ft_links(t_graph *graph, t_file *file);

/*
** get_paths.c
*/

void			reinit_visited(t_graph *g);
int				bfs_test(t_graph *g);
int				bfs_allpaths(t_graph *g);
int				get_path(t_graph *g);

/*
** move.c
*/

int				ants_at_end(t_graph *g);
void			move_ants(t_graph *g);

/*
** parser.c
*/

int				parser(int fd, t_graph *graph, t_file **file);

/*
** parser_alloc.c
*/

int				ft_malloc_graph(t_graph *graph);

/*
** parser_ants.c
*/

int				ft_ants(t_graph *graph, char *line);

/*
** parser_rooms.c
*/

int				ft_rooms(t_graph *graph, t_file *file, int command);

/*
** paths.c
*/

int				get_path_count(t_graph *g, int *size_paths, int npath);

/*
** printers.c
*/

void			print_paths(t_graph *g);

/*
** queue.c
*/

t_queue			*new_queue(void);
int				append_queue(t_queue *q, int room);
int				prepend_queue(t_queue *q, int room);
int				pop_queue(t_queue *q);
int				popback_queue(t_queue *q);

/*
** tools.c
*/

int				ft_isint(char *s, int start, int end);
void			skip_spaces(char *s, t_uint *i);

/*
** valider.c
*/

int				valid_nants(char *s);
int				valid_name(char *s, int imax);
int				valid_room(char *line, int i, int j);
int				valid_links(char *line);
int				valid_graph(t_graph *graph);

/*
** valider_auxiliaries.c
*/

int				ft_iscommentary(char *s);
int				ft_iscommand(char *s, int command);

#endif
