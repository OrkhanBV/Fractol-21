# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/27 01:52:05 by jremarqu          #+#    #+#              #
#    Updated: 2020/04/27 17:30:40 by jremarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, lib_refresh, all

################################################################################

#	INCLUDES_FRACTOL
INCLUDES_FILES_LIST =					\
				fractal.h				\

INCLUDES_DIR = 	./includes/
INCLUDES_FILES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES_LIST))

################################################################################

#	INCLUDES_LIBFT
LIBFT_DIR =								\
	./includes/libft/					\

################################################################################

#	FRACTOL
FRACTOL_NAME = 				fractol
FRACTOL_OBJ_DIR =			./objects/obj_fractol

#	SRCS & OBJ DIRS
SRC =						./srcs/
OBJ_DIR =					./objects/

FRACTOL_SRC = $(addprefix $(SRC), $(FRACTOL_SRC_NAME))
FRACTOL_OBJ = $(addprefix $(FRACTOL_OBJ_DIR), $(FRACTOL_OBJ_NAME))

FRACTOL_SRC_NAME = 						\
					main.c 				\
					helper.c 			\
					zoom.c 				\
					mouse.c 			\
					keyboard.c 			\
					fractals_initial.c	\
					mandelbar.c 		\
					chameleon.c 		\
					mandelbrot.c 		\
					colorising.c 		\
					julia.c 			\

FLAGS = 	         -Wall -Wextra -Werror
MLX_FLAGS =			 -L/usr/X11/lib /usr/X11/lib/libmlx_Linux.a -lmlx -lXext -lX11

################################################################################

FRACTOL_OBJ_NAME = $(FRACTOL_SRC_NAME:.c=.o)

$(FRACTOL_NAME): $(FRACTOL_OBJ) $(INCLUDES_FILES)
	@make lib_refresh
	@mkdir -p $(FRACTOL_OBJ_DIR)
	gcc $(FLAGS) -o $(FRACTOL_NAME) $(FRACTOL_OBJ) $(MLX_FLAGS) -lft -L $(LIBFT_DIR)
	@echo "\n"
	@echo "************************************************"
	@echo "*   JREMARQUE'S FRACTOL COMPILATION COMPLETE   *"
	@echo "************************************************"
	@echo "\n"

$(FRACTOL_OBJ_DIR)%.o: $(SRC)%.c $(INCLUDES_FILES)
	@mkdir -p $(FRACTOL_OBJ_DIR)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -o $@ -c $<

################################################################################

all: $(FRACTOL_NAME)

lib_refresh:
	@make -C $(LIBFT_DIR)

clean:
	@find . -name ".DS_Store" -delete
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(FRACTOL_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all


################################################################################
################################################################################
#
#                      			ЗАМЕТКИ
#
#					Часть 1 "Компиляция на маке"                              
# 	Я не уверен но возможно если заменинть MLX_FLAGS, как я указал ниже,
#   то должно скомпилиться и на маке меня не было возможности проверить, 
#	просьба отнестись с пониманием
# 	MLX_FLAGS =			-lmlx -framework OpenGL -framework AppKit
#
#					Часть 2 "Комментарии"
# 	Функция addprefix добавляет свой первый аргумент ко всем целям, 
# 	которые задает второй аргумент                  
#
#					Часть 3 "Ссылки"
# 	Ссылка на полезную статью по макефайлу
# 	https://habr.com/ru/post/111691/
#
################################################################################
################################################################################
