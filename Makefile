# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:20:23 by loicpapon         #+#    #+#              #
#    Updated: 2025/03/27 18:08:57 by loicpapon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	src/affichage.c \
				src/check.c \
				src/core.c \
				src/main.c \
				src/move.c \
				src/map.c \
				src/window_gest.c \

OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Paths to libft and minilibx
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# Libraries
LIBFT		= ${LIBFT_DIR}/libft.a
MLX			= ${MLX_DIR}/libmlx.a

%.o: %.c
	${CC} ${CFLAGS} -I. -I${LIBFT_DIR} -I${MLX_DIR} -c $< -o $@

all: ${NAME}

${NAME}: ${LIBFT} ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -L${LIBFT_DIR} -lft -L${MLX_DIR} -lmlx -lm -lX11 -lXext -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}

${MLX}:
	make -C ${MLX_DIR}

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re