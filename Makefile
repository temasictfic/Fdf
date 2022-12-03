CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -Ofast#-g -ggdb -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined 
RM = rm -f

NAME = fdf
LIBS = -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
SRCS = bresenham.c draw.c init.c keys.c main.c map.c mouse.c projections.c gnl/*.c


all: ${NAME}

bonus: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} ${LIBS} -o ${NAME}

clean:

fclean: clean
	$(RM) ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re