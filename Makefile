NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	./srcs/so_long.c \
		./srcs/ft_free.c \
		./srcs/ft_init.c \
		./srcs/rend_map.c \
		./srcs/ft_utils.c \
		./srcs/check_map.c \
		./srcs/check_map2.c\
		./srcs/flood_fill.c \
		./srcs/ft_read_map.c \
		./srcs/img_map_items.c \
		./srcs/ft_move_player.c 

OBJ = $(SRCS:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
MLX = ./minilibx-linux/libmlx.a
L_DIR = ./libft
LIBFT = $(L_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -L./minilibx-linux $(MLX_FLAGS) -o $(NAME) $(LIBFT)

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
