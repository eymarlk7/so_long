#include "../../include/so_long.h"

int check_map_char(char **map)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' 
            && map[y][x] != 'E' && map[y][x] != 'P')
            {
                ft_putstr_fd("Error\nfinding a invalid character\n", 2);        
                return (-1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int is_retangular(char **map)
{
    int width;
    int height;

    width = ft_strlen(map[0]);
    height = len_row(map);
    if (width == height)
    {
        ft_putstr_fd("Error\nmap is not retangular\n", 2);
        return (-1);
    }
    return (0);
}

int has_main_char(char **map)
{
    if (find_char(map, 'P') != 1)
    {
        ft_putstr_fd("Error\nthere is no player\n", 2);
        return (-1);
    }
    else if (find_char(map, 'E') != 1)
    {
        ft_putstr_fd("Error\nthere is no exit\n", 2);
        return (-1);
    }
    else if (find_char(map, 'C') < 1)
    {
        ft_putstr_fd("Error\nthere is no any colletible\n", 2);
        return (-1);
    }
    return (0);
}

void ft_check_all(char *path, char **map)
{
    if (ft_check_extension(path) == -1)
        ft_error(map);
    else if (map_around_walls(map) == -1)
        ft_error(map);
    else if (is_retangular(map) == -1)
        ft_error(map);
    else if (check_rows(map) == -1)
        ft_error(map);
    else if (has_main_char(map))
        ft_error(map);
    else if (check_map_char(map) == -1)
        ft_error(map);
    valid_path(map);
}

