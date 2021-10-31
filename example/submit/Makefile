CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g
NAME = push_swap

DIR_H = ./header/
DIR_S = ./
DIR_O = ./

SRC = 	libft_utils.c\
		linked_list.c\
		memory_utils.c\
		parse_utils.c\
		validate.c\
		operations/push.c\
		operations/swap.c\
		operations/rotate.c\
		operations/reverse_rotate.c\
		algorithm/sort_case.c\
		algorithm/sort_utils.c\
		algorithm/sort_merge.c\
		main.c\
	


SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re