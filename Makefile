NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =		so_long.c \
		rend_map.c \
		ft_utils.c \
		check_map.c \
		flood_fill.c \
		handler_hooks.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
MLX = ./minilibx-linux/libmlx.a
L_DIR = ./libft
LIBFT = $(L_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -L./minilibx-linux $(MLX_FLAGS) -o $(NAME) $(LIBFT)

$(MLX):
	$(MAKE) -C ./minilibx-linux

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(OBJ)
	@$(MAKE) clean -C ./minilibx-linux
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	@$(MAKE) clean -C ./minilibx-linux
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
