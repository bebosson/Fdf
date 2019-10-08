# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebosson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 13:00:20 by bebosson          #+#    #+#              #
#    Updated: 2019/09/27 17:36:43 by bebosson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_PATH = srcs
SRC_NAME = connect.c echelle.c grille_display.c ligne.c rotation.c \
	   couleur.c errors.c  image.c list_map.c rotation_list.c  \
	   deal_key_couleur.c ft_coor.c info_window.c main.c translation.c \
	   deal_key_rotation.c ft_free_all.c iso.c \

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

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
