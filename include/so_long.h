#ifndef SO_LONG_H

# define SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_point
{
    int y;
    int x;
}   t_point;

typedef struct s_img
{
    void    *img_0;
    void    *img_1;
    void    *img_c;
    void    *img_e;
    void    *img_p;
}   t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     count_step;
    t_point posix;
    t_img   img;
}   t_game;


t_point find_posix(char **map, char c);

void    ft_free(char **str);
void    ft_error(char **str);

void	ft_init_game(char **argv);
void    valid_path(char **cpy_map);
void	print_map_window(t_game *game);
void    close_img(void *mlx, t_img *img);
void	get_img_path(char *mlx, t_img *img);
void    ft_check_all(char *path, char **map);
void	get_init_mlx(t_game *game, char **argv);
void	print_image(t_game *game, char c, int w, int h);
void    ft_check_path(char **map, int y, int x, t_point begin);
void	ft_move_other_pos(t_game *game, t_point begin, int y, int x);

int len_row(char **map);
int check_rows(char **map);
int ft_open_file(char *argv);
int	close_game(t_game *game);
int	window_stop(t_game *game);
int	window_close(t_game *game);
int map_around_walls(char **map);
int find_char(char **map, char c);
int ft_check_extension(char *argv);
int	keypress(int key, t_game *game);

char    *ft_read_map(int fd);
char    **ft_get_map(char *map_path);

#endif