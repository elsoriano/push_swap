NAME = push_swap
SRCDIR = src
OBJDIR = obj
SRCSFILES = compound_movements.c \
			errors.c \
			logic.c \
			movements.c \
			push_swap_utils.c \
			push_swap.c \
			sort.c \
			three.c
SRCS = $(addprefix $(SRCDIR)/,$(SRCSFILES))
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
HEAD = -Iinc
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

obj:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re