NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	./srcs/main.c \
		./srcs/ft_exit.c \
		./srcs/read_map.c \
		./srcs/ft_utils.c \
		./srcs/finish_game.c \
		./srcs/ft_init_game.c \
		./srcs/ft_move_player.c \
		./srcs/validations/ft_check_map.c \
		./srcs/validations/ft_check_path.c \
		./srcs/validations/ft_check_walls.c \
		./srcs/validations/ft_check_extension.c

OBJ = $(SRCS:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
MLX = ./minilibx-linux/libmlx.a
L_DIR = ./libft
LIBFT = $(L_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L./minilibx-linux $(MLX_FLAGS) -o $(NAME) $(LIBFT)

$(MLX):
	$(MAKE) -s -C ./minilibx-linux

$(LIBFT):
	$(MAKE) -s -C ./libft

clean:
	rm -f $(OBJ)
	@$(MAKE) clean -s -C ./minilibx-linux
	@$(MAKE) clean -s -C ./libft

fclean: clean
	rm -f $(NAME)
	@$(MAKE) clean -s -C ./minilibx-linux
	@$(MAKE) fclean -s -C ./libft

re: fclean all

.PHONY: all clean fclean re
