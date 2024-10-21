NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	so_long.c \
		check_map.c
OBJ = $(SRC:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm
MLX = ./minilibx-linux/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L./minilibx-linux $(MLX_FLAGS) -o $(NAME)

$(MLX):
	$(MAKE) -C ./minilibx-linux

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
