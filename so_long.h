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
    char    **map;
    void    *img_c;
    void    *img_p;
    void    *img_1;
    void    *img_0;
    void    *img_e;
}   t_data;

typedef struct 	s_point 
{
    int 		x;				
    int 		y;
} 				t_point;



/* FUNCTIONS */
int on_keypress(int keysym, t_data *data);
int on_destroy(t_data *data);
void    handler_hooks(t_data data);
void    check_status(int nbr);
void    init_items(t_data *data);
void    initiate_struct(t_data *data, char **map);
void    print_map(char  **map, t_data *data,  t_point point);

int     check_dup(char **map);
int     map_len_x(char *line);
int     map_len_y(char **map);
int     check_path(char **map);
int     check_line(char **map);
int     check_walls(char **map);
int     check_walls2(char **map);
int     map_extension(char *map);
int     check_map_args(char **map);
int     check_rectangle(char **map);
int     find_char(char **map, char c);
int    ft_check_map(char *path, char **map);

char	*get_next_line(int fd);


#endif