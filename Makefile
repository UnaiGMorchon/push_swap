# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ugarcia- <ugarcia-@student.42urduliz.com>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/06/10 12:43:36 by patperez            #+#    #+#             #
#   Updated: 2026/07/17 10:44:10 by ugarcia-           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRCS = ft_push.c ft_rotate.c ft_swap.c ft_reverse.c \
 ft_pushswap_utils1.c ft_pushswap_utils2.c \
 push_swap.c ft_bubble_sort.c ft_bucket.c \
 ft_input_conversion.c main.c disorder_adaptive_algo.c ft_radix.c \
 ft_shortlist_sort.c

LIBFT_DIR = ./libft
PRINTF_DIR = ./printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re