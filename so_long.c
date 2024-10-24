#include "so_long.h"

char **get_map(char *map_path)
{
    int fd;
    char *map_str;
    char    **split;

    fd = open(map_path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error\n");
        exit(0);
    }
    map_str = get_next_line(fd);
    split = ft_split(map_str, '\n');
    free(map_str);
    return(split);
}
void initiate_struct(t_data *data, char **map)
{
    data->map = map;
    data->count = 0;
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, 33 * map_len_x(data->map[0]), 33 * map_len_y(data->map), "So_long");
    init_items(data);
}
int start_player(int keysym, t_data *data)
{
    t_point player;
    
    player.y = 0;
    player.x = 0;
    on_keypress(keysym, data);
    if (keysym == 100)
        ft_mov_player_right(data, &player);
    else if (keysym == 97)
        ft_mov_player_left(data, &player);
    else if (keysym == 119)
        ft_mov_player_up(data, &player);
    else if (keysym == 115)
        ft_mov_player_down(data, &player);
    if (data->map[player.y][player.x] == 'E' && find_char(data->map, 'C') == 0)
        exit(0);
    return (keysym);
}
int main(int ac, char **av)
{
    if (ac != 2)
        return (0);
    char **map;
    char **map1;
    t_data  data;

    map = get_map(av[1]);
    map1 = get_map(av[1]);
    if (ft_check_map(av[1], map1) != 0)
    {
        check_status(ft_check_map(av[1], map1));
        free(map);
        free(map1);
        exit(1);
    }
    initiate_struct(&data, map);
    print_map(map, &data, (t_point){0, 0});
    // handler_hooks(data);
    mlx_key_hook(data.window, start_player, &data);
    mlx_loop(data.mlx);
    return 0;
}

