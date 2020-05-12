# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/27 01:52:05 by jremarqu          #+#    #+#              #
#    Updated: 2020/05/01 15:30:08 by jremarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = fractol

# CC = gcc
# FLAGS = -Wall -Werror -Wextra
# LIBRARIES = -lm -lft\
# 	-L$(LIBFT_DIRECTORY) #-L$(MINILIBX_DIRECTORY)
	
# INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

# LIBFT = $(LIBFT_DIRECTORY)libft.a
# LIBFT_DIRECTORY = ./includes/libft/
# LIBFT_HEADERS = $(LIBFT_DIRECTORY)

# MINILIBX = $(MINILIBX_DIRECTORY)libmlx_Linux.a
# MINILIBX_DIRECTORY = ./minilibx/
# MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

# MLX_FLAGS =			 -L/minilibx /minilibx/libmlx_Linux.a -lmlx -lXext -lX11			
# # MLX_FLAGS =			 -L/usr/X11/lib /usr/X11/lib/libmlx_Linux.a -lmlx -lXext -lX11

# HEADERS_LIST = \
# 	fractal.h  \

# HEADERS_DIRECTORY = ./includes/
# HEADERS = $($(HEADERS_DIRECTORY), $(HEADERS_LIST))

# SOURCES_DIRECTORY = ./srcs/
# SOURCES_LIST =					\
# 			main.c				\
# 			helper.c 			\
# 			zoom.c 				\
# 			mouse.c 			\
# 			keyboard.c 			\
# 			fractals_initial.c	\
# 			mandelbar.c 		\
# 			chameleon.c 		\
# 			mandelbrot.c 		\
# 			colorising.c 		\
# 			julia.c 			\

# SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS_DIRECTORY = objects/
# OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
# OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# # COLORS

# GREEN = \033[0;32m
# RED = \033[0;31m
# RESET = \033[0m

# .PHONY: all clean fclean re

# all: $(NAME)

# $(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
# 	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
# 	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
# 	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

# # $(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
# # 	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
# # 	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
# # 	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

# $(OBJECTS_DIRECTORY):
# 	@mkdir -p $(OBJECTS_DIRECTORY)
# 	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

# $(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
# 	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
# 	@echo "$(GREEN).$(RESET)\c"

# $(LIBFT):
# 	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
# 	@$(MAKE) -sC $(LIBFT_DIRECTORY)

# $(MINILIBX):
# 	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
# 	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

# clean:
# 	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
# 	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
# 	@rm -rf $(OBJECTS_DIRECTORY)
# 	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
# 	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

# fclean: clean
# 	@rm -f $(MINILIBX)
# 	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
# 	@rm -f $(LIBFT)
# 	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
# 	@rm -f $(NAME)
# 	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

# re:
# 	@$(MAKE) fclean
# 	@$(MAKE) all


##########################################
##########################################
##########################################
##########################################

# JREMAHQU_IS_BOSS

.PHONY: clean, fclean, re, lib_refresh, all, mlx

################################################################################

MLX_DIR = ./minilibx/


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
# MLX_FLAGS =			 -L/usr/X11/lib /usr/X11/lib/libmlx_Linux.a -lmlx -lXext -lX11
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
