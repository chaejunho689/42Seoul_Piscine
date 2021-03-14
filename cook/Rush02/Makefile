NAME   = rush-02
SRCDIR = src
INCDIR = includes
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)
CC      = gcc
CFLAGS = -Wall -Wextra -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ -I $(INCDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run :
	./$(NAME)

norm :
	norminette */*.[ch]
