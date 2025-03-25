
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror


SRCS = get_next_line.c get_next_line_utils.c main.c utils.c utils_2.c
OBJECTS = $(SRCS:.c=.o)


NAME = so_long


all: $(NAME)


$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)


%.o: %.c so_long.h get_next_line.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.SECONDARY : $(OBJECTS)

.PHONY: all clean fclean re