# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchae <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/14 18:06:01 by jchae             #+#    #+#              #
#    Updated: 2021/03/14 19:23:12 by jchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror
TARGET = rush-02
INCDIR = includes
SRCDIR = srcs
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET):
	gcc $(CFLAG) -o $(TARGET) $(SRCS) -I $(INCDIR)
	
run :
	./$(TARGET)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(TARGET)

Norm	:
	norminette */*.[ch]
	