# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 11:07:13 by dbirge-c          #+#    #+#              #
#    Updated: 2018/04/10 16:45:20 by dbirge-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = -I includes/
SRCS =	app_allocator.c \
		args_handler.c \
		coloring.c \
		colors.c \
		draw.c \
		events.c \
		frac_burning_ship.c \
		frac_julia.c \
		frac_mandelbrot.c \
		input_handlers.c \
		main.c \
		math_helpers.c \
		mouse_handler.c \
		render.c \
		sdl_allocator.c \
		update.c \
		utilities.c \
		vector2f.c \
		vector2i.c \
		multithreading.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SDL = `sdl2-config --cflags --libs`

all: library $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SDL) $(OBJS) -L ./libft -l ft -o $@
	@echo "$(NAME) compiled"

library:
	@$(MAKE) -C libft

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C ./libft clean
	@echo "$(NAME) cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
