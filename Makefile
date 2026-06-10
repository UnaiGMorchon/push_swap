# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patperez <patperez@student.42urduliz.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/10 12:43:36 by patperez          #+#    #+#              #
#    Updated: 2026/06/10 12:46:14 by patperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
