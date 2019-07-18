# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebosson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 13:00:20 by bebosson          #+#    #+#              #
#    Updated: 2019/07/11 14:38:32 by bebosson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRC_PATH = srcs
SRC_NAME = connect.c deal_key_rotation.c ft_coor.c grille_display.c 		\
		main.c translation.c couleur.c errors.c image.c			\
		ligne_juepee.c deal_key_couleur.c  			\
		get_next_line.c iso.c list_map.c rotation.c							\

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang -g
#CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes

LDFLAGS = -L libft
LDLIBS = -O2 -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of Fdf:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Fdf: Removing Objs"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Fdf : Removing Fdf"

re: fclean all

.PHONY: all clean fclean re
