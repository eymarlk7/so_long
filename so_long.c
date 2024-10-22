#include "so_long.h"
char **get_map(char *map_path)
{
    int fd;
    char *map_str;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\n");
        exit(0);
    }
    map_str = get_next_line(fd);
    return(ft_split(map_str, '\n'));
}
void initiate_struct(t_data *data, char **map)
{
    data->map = map;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    char **map;
    t_data  *data;

    data = (t_data*) malloc(sizeof(t_data));
    map = get_map(av[1]);
    ft_check_map(av[1], map);
    initiate_struct(data, map);
    data->mlx = mlx_init();
    mlx_new_window(data->mlx, 100 * map_len_x(data->map[0]), 100 * map_len_y(data->map), "So_long");

    mlx_loop(data->mlx);
    return 0;
}

//  int i = 0;
//     int fd = open("./my.txt", O_RDONLY);
//     char *str = get_next_line(fd);
//     data.map = ft_split(str, '\n');
//     ft_check_map(data.map);