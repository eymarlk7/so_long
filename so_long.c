#include "so_long.h"
int map_len_y(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}

int map_len_x(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        i++;
    }
    return(i);
}
void check_walls(char **map)
{
    int x;
    int y;
    int  y_len;
    int x_len;

    x = 0;
    y = 0;
   y_len = map_len_y(map);
   x_len = map_len_x(map[0]);
    while (map[0][x])
    {
        if(map[0][x] != '1')
        {
            ft_printf("Error\n");
            exit(0);
        }
        if(map[y_len - 1][x] != '1')
        {
            ft_printf("Error\n");
            exit(0);
        }
        x++;
    }
   while (map[y] != NULL)
    {
        if(map[y][0] != '1')
        {
            ft_printf("Error\n");
            exit(0);
        }
        if(map[y][x_len - 1] != '1')
        {
            ft_printf("Error\n");
            exit(0);
        }
        y++;
    }
}

void check_rectangle(char **map)
{
    int y_len;
    int x_len;

    y_len = map_len_y(map);
    x_len = map_len_x(map[0]);
    if (y_len == x_len)
    {
        ft_printf("Error\n");
        exit(0);
    }
}

void ft_check_map(char **map)
{
    check_rectangle(map);
    ch
    check_walls(map);
}
int main(void)
{
    int fd = open("./my.txt", O_RDONLY);
    char *str = get_next_line(fd);
    char **map = ft_split(str, '\n');
    ft_check_map(map);
    return 0;
}