# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ugarcia- <ugarcia-@student.42urduliz.com>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/06/10 12:43:36 by patperez            #+#    #+#             #
#   Updated: 2026/07/02 12:26:54 by ugarcia-           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push.c ft_rotate.c ft_swap.c ft_reverse.c \
 ft_pushswap_utils1.c ft_pushswap_utils2.c \
 push_swap.c ft_bubble_sort.c ft_bucket.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re