# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 02:11:04 by loicpapon         #+#    #+#              #
#    Updated: 2025/04/28 12:37:09 by loicpapon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
SRC_DIR		= src
SRCS		= $(SRC_DIR)/move.c \
              $(SRC_DIR)/found_chemin_exit.c \
              $(SRC_DIR)/found_chemin.c \
              $(SRC_DIR)/game.c \
              $(SRC_DIR)/get_all_position.c \
              $(SRC_DIR)/image.c \
              $(SRC_DIR)/info_map.c \
              $(SRC_DIR)/list.c \
              $(SRC_DIR)/main.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/utils.c \
              $(SRC_DIR)/so_long.c

# Object files
OBJS		= ${SRCS:.c=.o}

# Target name
NAME		= so_long

# Compiler and flags
CC			= gcc -Wall -Werror -Wextra
CFLAGS		= -Wall -Wextra -Werror

# Paths to libft and minilibx
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# Libraries
LIBFT		= ${LIBFT_DIR}/libft.a
MLX			= ${MLX_DIR}/libmlx.a

# Compilation rule for object files
%.o: %.c
	${CC} ${CFLAGS} -I. -Iinclude -I${LIBFT_DIR} -I${MLX_DIR} -c $< -o $@

# Default target
all: ${NAME}

# Linking rule
${NAME}: ${LIBFT} ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -L${LIBFT_DIR} -lft -L${MLX_DIR} -lmlx -lm -lX11 -lXext -o ${NAME}

# Build libft
${LIBFT}:
	make -C ${LIBFT_DIR}

# Build minilibx
${MLX}:
	make -C ${MLX_DIR}

# Clean object files
clean:
	rm -f ${OBJS}

# Clean all
fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean
	make -C ${MLX_DIR} clean

# Rebuild everything
re: fclean all