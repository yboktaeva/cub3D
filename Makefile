# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 13:34:14 by yuboktae          #+#    #+#              #
#    Updated: 2023/11/28 14:51:32 by yuboktae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR 	=	includes/
LIBFT_PATH	=	libft/
MLX_PATH	=	minilibx-linux/
SRC_FILES	=	main.c init_img.c get_cub_file.c start_game.c key_events.c ft_error.c \
				draw_game.c destroy_game.c mlx_utils.c parsing.c parse_utils.c \
				parse_map.c get_data.c check_rgb.c get_map.c ray_casting.c 


INC			=	$(addprefix -I, $(INC_DIR))
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
DEP			=	$(OBJ:.o=.d)

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	-I/usr/local/include -I$(INC_DIR) -Imlx_linux
LIBFT		=	$(LIBFT_PATH)/libft.a
MLX			=	$(MLX_PATH)/libmlx.a

all:	$(NAME) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) all

$(MLX):
	@$(MAKE) -C $(MLX_PATH) all

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "$(BGreen)******* Cub3D: Compilation complete! *******$(BEnd)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIBFT) -lXext -lX11 -lm -lz -L$(MLX_PATH) -lmlx -Lmlx_linux


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INC) -Imlx_linux -MMD -MP -o $@ -c $<

-include $(DEP)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME) $(LIBFT)
	@echo "$(BBlue)******* Cleanup complete! *******$(BEnd)"

re: fclean all

.PHONY: libft minilibx all clean fclean re mlx

BGreen=\033[1;32m
BBlue=\033[1;34m
BEnd=\033[1m
