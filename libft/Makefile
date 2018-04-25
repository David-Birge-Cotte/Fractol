# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 12:44:54 by dbirge-c          #+#    #+#              #
#    Updated: 2017/12/12 11:32:36 by dbirge-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
			ft_strcat.c ft_strncat.c \
			ft_strchr.c ft_strrchr.c ft_strlcat.c \
			ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_strlen.c ft_putchar.c ft_putstr.c  ft_putendl.c ft_putnbr.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_tolower.c ft_toupper.c \
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			ft_strsplit.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c \
			ft_isupper.c ft_islower.c ft_abs.c ft_sqrt.c ft_lstlexinsert.c \
			ft_lstaddend.c ft_list_size.c get_next_line.c ft_tablen.c \
			ft_swap.c ft_absl.c
FLAGS = -Wall -Wextra -Werror
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	 @gcc -c -o $@ $<

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
