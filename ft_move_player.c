#include "so_long.h"

void    ft_mov_player_right(t_data *data, t_point *player)
{
        *player = find_player(data->map);
        if (data->map[player->y][player->x + 1] != '1' && data->map[player->y][player->x + 1] != 'E')
        {
                data->map[player->y][player->x] = '0';
                data->map[player->y][player->x + 1] = 'P';
                print_map(data->map, data, (t_point){0, 0});
                data->count++;
                ft_printf("%d\n", data->count);
        }
        player->x++;
}

void    ft_mov_player_left(t_data *data, t_point *player)
{

        *player = find_player(data->map);
        if (data->map[player->y][player->x - 1] != '1' && data->map[player->y][player->x - 1] != 'E')
        {
                data->map[player->y][player->x] = '0';
                data->map[player->y][player->x - 1] = 'P';
                print_map(data->map, data, (t_point){0, 0});
                data->count++;
                ft_printf("%d\n", data->count);
        }
        player->x--;
}
void    ft_mov_player_up(t_data *data, t_point *player)
{
        *player = find_player(data->map);
        if (data->map[player->y - 1][player->x] != '1' && data->map[player->y - 1][player->x] != 'E')
        {
                data->map[player->y][player->x] = '0';
                data->map[player->y - 1][player->x] = 'P';
                print_map(data->map, data, (t_point){0, 0});
                data->count++;
                ft_printf("%d\n", data->count);
        }
        player->y--;
}

void    ft_mov_player_down(t_data *data, t_point *player)
{
        *player = find_player(data->map);
        if (data->map[player->y + 1][player->x] != '1' && data->map[player->y + 1][player->x] != 'E')
        {
                data->map[player->y][player->x] = '0';
                data->map[player->y + 1][player->x] = 'P';
                print_map(data->map, data, (t_point){0, 0});
                data->count++;
                ft_printf("%d\n", data->count);
        }
        player->y++;
}
