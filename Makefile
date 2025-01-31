# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2025/01/31 16:18:38 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractal
CFLAGS		= -Wall -Wextra -Werror -g -I include -I libft -I . # -I path for .h
RM			= rm -f # force remove
CC			= cc # compiler
INCLUDE		= -L ./libft -lft ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm # looks for *.a files
MAKEFLAGS 	= --no-print-directory # silences "entering, leaving dir..."

# Check all the flags from Oceano video. Let's go to the third one and learn.

SRC		= 	fractal.c #src/push_swap.c

OBJ		:=	$(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
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
	@echo "fractal is super clean"

re:	fclean all

.PHONY:	all clean fclean re
