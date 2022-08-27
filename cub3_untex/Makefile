# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 13:42:43 by aaljaber          #+#    #+#              #
#    Updated: 2022/08/27 05:49:10 by aaljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./SRC/main.c ./SRC/cub_init.c ./SRC/cub_get_map.c ./SRC/cub_math.c ./SRC/cub_get_wallcoord.c ./SRC/cub_tools.c ./SRC/cub_initial_dis.c ./SRC/cub_grid_checkers.c ./SRC/cub_raycast.c ./SRC/cub_wall_check.c ./SRC/cub_grid_coordcheck.c ./SRC/cub_key.c
		

OBJ = ${SRC:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

LINKS = -L MLX -l MLX -framework OpenGl -framework Appkit -lz

LIBFT = ./LIB/LIBFT/libft.a 

GNL = ./LIB/GNL/get_next_line.c ./LIB/GNL/get_next_line_utils.c

RM = rm -rf

all: ${OBJ}
	${MAKE} -C ./MLX
	${MAKE} -C ./LIB/LIBFT
	${CC} ${FLAGS} ${LINKS} ${OBJ} ${LIBFT} ${GNL} -o cub3D

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} cub3D
	${MAKE} clean -C ./MLX
	${MAKE} fclean -C ./LIB/LIBFT

re: fclean all