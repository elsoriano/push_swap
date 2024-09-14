CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar
ARFLAGS = rcs
NAME = push_swap.out
SRCS = src/push_swap.c \
			src/push_swap_utils.c \
			src/errors.c \
			src/movements.c \
			src/compound_movements.c \
			src/three.c \
all: $(NAME)

$(NAME): inc/push_swap.h
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY: clean fclean re bonus