# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2025/01/30 21:37:32 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractal
CFLAGS		= -Wall -Wextra -Werror -g -I include -I libft -I .
RM			= rm -f
CC			= cc
INCLUDE		= -L ./libft -lft
MAKEFLAGS 	= --no-print-directory

# Check all the flags from Oceano video. Let's go to the third one and learn.

SRC		= 	#src/push_swap.c

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

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft/

re:	fclean all

.PHONY:	all clean fclean re
