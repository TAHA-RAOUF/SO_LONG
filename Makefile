
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I./include  
CLINK = -L/usr/include/minilibx-linux/ -lmlx -lX11 -lXext

SRCS = src/get_next_line.c \
       src/get_next_line_utils.c \
       src/main.c \
       src/utils.c \
       src/utils_2.c \
       src/check_error.c \
       src/flood_fill.c \
       src/mlx_fun.c \
       src/moves.c \
       src/nbr_print.c

OBJECTS = $(SRCS:.c=.o)


NAME = so_long


all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(CLINK) -o $(NAME)


%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.SECONDARY : $(OBJECTS)

.PHONY: all clean fclean re
