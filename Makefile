# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 15:34:26 by tbruha            #+#    #+#              #
#    Updated: 2024/12/06 13:06:52 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror -g -I include -I libft -I .
RM			= rm -f
CC			= cc
INCLUDE		= -L ./libft -lft
MAKEFLAGS 	= --no-print-directory

SRC		= 	src/push_swap.c src/lst_utils1.c src/lst_utils2.c \
			src/operations_swap_and_push.c src/operations_rotations.c \
			src/operations_reverse_rotations.c src/sorting1.c src/sorting2.c \
			src/errors_free_and_other.c src/nodes_info1.c src/nodes_info2.c

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
