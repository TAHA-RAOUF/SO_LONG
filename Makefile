
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
CLINK = -L/usr/include/minilibx-linux/ -lmlx -lX11 -lXext

SRCS = get_next_line.c get_next_line_utils.c main.c utils.c utils_2.c check_error.c flood_fill.c mlx_fun.c test.c
OBJECTS = $(SRCS:.c=.o)


NAME = so_long


all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(CLINK) -o $(NAME)


%.o: %.c so_long.h get_next_line.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.SECONDARY : $(OBJECTS)

.PHONY: all clean fclean re
