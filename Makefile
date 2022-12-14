# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sciftci <sciftci@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 04:46:15 by sciftci           #+#    #+#              #
#    Updated: 2022/12/14 04:21:15 by sciftci          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -Ofast -flto -march=native#-g -ggdb -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined 
RM = rm -f

NAME = fdf
LIBS = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
SRCS = bresenham.c projections.c draw.c init.c keys.c main.c mouse.c read.c utils.c gnl/*.c


all: ${NAME}

bonus: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} ${LIBS} -o ${NAME}

clean:

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re