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

char	*get_next_line(int fd);
void    ft_check_map(char **map);

#endif