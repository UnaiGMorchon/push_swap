# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ugarcia- <ugarcia-@student.42urduliz.com>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/06/10 12:43:36 by patperez            #+#    #+#             #
#   Updated: 2026/06/23 07:50:06 by ugarcia-           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push.c ft_ra.c ft_ss.c ft_sa.c ft_sb.c ft_reverse.c \
ft_pushswap_utils1.c push_swap.c

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