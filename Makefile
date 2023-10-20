# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:34:16 by nzhuzhle          #+#    #+#              #
#    Updated: 2023/10/05 18:25:26 by nzhuzhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -I ./ -g -fsanitize=address
ML_FLAGS = -framework OpenGL -framework AppKit

SRC = fractol.c aux.c mandelbrot.c 
#julia.c burning_ship.c
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

SRC_BONUS = 
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS_BONUS = $(SRC_BONUS:.c=.d)

SRC_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft --no-print-directory

SRC_ML = ./minilibx/libmlx.a
MAKE_ML = make -C minilibx --no-print-directory

%.o: %.c Makefile
	$(CC) $(FLAGS) -Iminilibx -Ilibft -c $< -o $@

all: make_lib make_ml $(NAME)

make_lib: 
	$(MAKE_LIBFT)

make_ml:
	$(MAKE_ML)

-include $(DEPS)
$(NAME): $(OBJ) $(SRC_LIBFT) $(SRC_ML)
	$(CC) $(FLAGS) -Lminilibx $(ML_FLAGS) $(^) -o $(NAME)

bonus:  make_lib make_ml .bonusf

-include $(DEPS_BONUS)
.bonusf: $(OBJ_BONUS) $(SRC_LIBFT) $(SRC_ML)
	$(CC) $(FLAGS) $(ML_FLAGS) $(^) -o $(NAME)
	@touch .bonusf

clean:
	rm -f $(OBJ) $(DEPS) $(OBJ_BONUS) $(DEPS_BONUS)
	$(MAKE_LIBFT) clean
	$(MAKE_ML) clean

fclean: clean
	rm -f $(NAME) .bonusf
	$(MAKE_LIBFT) fclean
	$(MAKE_ML) fclean

re: fclean all

.PHONY: all clean fclean re
