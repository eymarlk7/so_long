#ifndef SO_LONG_H

# define SO_LONG_H
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
 #include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

typedef struct  s_data
{
    void    *mlx;
    void    *window;
    char  **map;
}   t_data;



/* FUNCTIONS */

int     check_dup(char **map);
int     map_len_x(char *line);
int     map_len_y(char **map);
int     check_line(char **map);
int     check_walls(char **map);
int     check_walls2(char **map);
int     map_extension(char *map);
int     check_map_args(char **map);
int     check_rectangle(char **map);
int     check_collectible(char **map);

char	*get_next_line(int fd);

void    ft_check_map(char *path, char **map);

#endif