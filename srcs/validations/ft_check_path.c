#include "../../include/so_long.h"


void    ft_check_path(char **map, int y, int x, t_point begin)
{
    if (map[y][x] == '1')
        return ;
    if (map[y][x] == '-')
        return ;
    if (map[y][x] == 'E')
        return;
    map[y][x] = '-';
    ft_check_path(map, (y + 1), x, begin);
    ft_check_path(map, (y - 1), x, begin);
    ft_check_path(map, y, (x + 1), begin);
    ft_check_path(map, y, (x - 1), begin);   
}

void    valid_path(char **cpy_map)
{
    t_point posix;
    int count_c;

    count_c = 0;
    posix = find_posix(cpy_map, 'P');
    ft_check_path(cpy_map, posix.y, posix.x, posix);
    count_c = find_char(cpy_map, 'C');
    if (count_c != 0)
    {
        ft_putstr_fd("Error\npath invalid\n", 2);
        ft_free(cpy_map);
        exit(1);
    }
    ft_free(cpy_map);
}