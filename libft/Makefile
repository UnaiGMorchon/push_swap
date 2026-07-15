# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ugarcia- <ugarcia-@student.42urduliz.com>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/04/28 07:22:33 by ugarcia-            #+#    #+#             #
#   Updated: 2026/07/09 13:45:53 by ugarcia-           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atol.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c \
ft_strlcat.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_isalpha.c \
ft_isprint.c ft_memcpy.c  ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_toupper.c \
ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlen.c \
ft_strrchr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilation completed: $@"

clean:
	rm -f $(OBJS) 
	@echo "Deleted object files"

fclean: clean
	rm -f $(NAME)
	@echo "Removed executable"

re: fclean all

.PHONY: all clean fclean re
