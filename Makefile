# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 11:18:01 by loicpapon         #+#    #+#              #
#    Updated: 2025/03/19 15:57:59 by loicpapon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:20:23 by loicpapon         #+#    #+#              #
#    Updated: 2025/02/19 16:46:51 by Lopapon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	src/main.c \
				src/map_gest.c \
				utils.c \
				map.c \
				
OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= gcc
LIBFT		= 
CFLAGS		= -Wall -Wextra -Werror

%.o: %.c libft.h
	${CC} ${CFLAGS} -I. -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re