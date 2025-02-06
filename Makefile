# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2025/02/06 03:08:26 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# future: CFLAGS, HEADERS, LIBS, INCLUDE all separate

NAME		= fractol
CFLAGS		= -Wall -Wextra -Werror -g -I include -I libft -I MLX42/include
RM			= rm -rf # force recursive remove
CC			= cc # compiler
INCLUDE		= -L ./libft -lft ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm # looks for *.a files
MAKEFLAGS 	= --no-print-directory # silences "entering, leaving dir..."

SRC		= 	fractal.c math.c utils.c rendering.c #src/push_swap.c

OBJ		:=	$(SRC:%.c=%.o)

all: $(NAME)

MLX42/build/libmlx42.a:
	@cmake MLX42/ -B MLX42/build && make -C MLX42/build -j4
	@echo "MLX42 created"

$(NAME): $(OBJ) MLX42/build/libmlx42.a
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@make clean -C libft/
	@echo "fractal is clean"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft/
	@$(RM) MLX42/build
	@echo "fractal is super clean"

re:	fclean all

.PHONY:	all clean fclean re
