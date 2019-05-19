# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efouille <efouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 01:48:57 by efouille          #+#    #+#              #
#    Updated: 2019/03/17 02:00:03 by efouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in

CC=clang
MAKE=make

override CFLAGS+= -Wall -Werror -Wextra

LDFLAGS=-Llibft -lft

SOURCE=lem_in.c cleanup.c errors.c ft_links.c \
	move.c printers.c paths.c parser.c parser_ants.c parser_rooms.c  \
	tools.c valider.c ants_in_paths.c get_paths.c ford_fulkerson.c \
	bfs_ff.c bellman_ford_queue.c queue.c bellman_ford_flow.c \
	bellman_ford_spfa.c bellman_ford_common.c valider_auxiliaries.c \
	parser_alloc.c file.c

SOURCE:=$(addprefix src/, ${SOURCE})

HEADER=lem_in.h lm_types.h
HEADER:=$(addprefix includes/, ${HEADER})

OBJ=${SOURCE:.c=.o}

.PHONY: all libft clean fclean re

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c -Ilibft/includes -Iincludes $< -o $@
	@echo [$(NAME)] $@

libft: libft.a

libft.a:
	@$(MAKE) -C libft $(RULE)

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
