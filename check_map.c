#include "so_long.h"
#include "string.h"

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


int    check_collectible(char **map)
{
    int y;
    int x;
    int count;

    y = 0;
    x = 0;
    count = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    if (count < 1)
    {
        write(2, "Error 7\n", 7);
        return (-1);
    }
    return (0);
}

int	check_dup(char **map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	if (count > 2 || count < 2)
    {
        write(2, "Error 6\n", 7);
        return (-1);
    }
    return (0);
}

int    check_map_args(char **map)
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
            if (map[y][x] != '0' && map[y][x] != '1' 
			&& map[y][x] != 'C' && map[y][x] != 'E'
			&& map[y][x] != 'P')
            {
                write(2, "Error 5\n", 7);
                return (-1);
            }
			x++;
        }
        y++;
    }
    return (0);
}

int    check_walls2(char **map)
{
    int y;
    int x_len;

    y = 0;
    x_len = map_len_x(map[0]);
    while (map[y] != NULL)
    {
        if(map[y][0] != '1' || map[y][x_len - 1] != '1')
            return (-1);
		y++;
    }
    return (0);
}

int check_walls(char **map)
{
    int x;
    int  y_len;

    x = 0;
    y_len = map_len_y(map);
    while (map[0][x])
    {
        if(map[0][x] != '1' || map[y_len - 1][x] != '1')
            return (-1);
        x++;
    }
    return (0);
}
int check_line(char **map)
{
    int x_len;
    int y;
    int i;

    x_len = map_len_x(map[0]);
    y = 0;
    i = 0;
    while (map[y])
    {
        i = 0;
        while (map[y][i])
            i++;
        if (i != x_len)
        {
            write(2, "Error 3\n", 7);
            return (-1);
        }
        y++;
    }
    return (0);
}

int check_rectangle(char **map)
{
    int y_len;
    int x_len;

    y_len = map_len_y(map);
    x_len = map_len_x(map[0]);
    if (y_len == x_len)
    {
        write(2, "Error 2\n", 7);
        return (-1);
    }
    return (0);
}
int    map_extension(char *map)
{
    size_t  map_size;
    char    *str;

    map_size = ft_strlen(map);
    str = ft_substr(map, map_size - 4, map_size - 1);
    if (map_size > 4)
    {
        if (ft_strcmp(str, ".ber") != 0)
        {
            write(2, "Error 1\n", 7);
            free(str);
            return (-1);
        }
    }
    return (0);
}

void ft_check_map(char *path, char **map)
{
    if (map_extension(path) != 0)
        exit(1);
    else if (check_rectangle(map) != 0)
        exit(1);
    else if ((check_line(map) != 0))
        exit(1);
    else if (check_walls(map) != 0 && check_walls2(map) != 0)
    {   
        write(2, "Error 4\n", 7);
        exit(1);
    }
    else if (check_map_args(map) != 0)
        exit(1);
    else if (check_dup(map) != 0)
        exit(1);
    else if (check_collectible(map) != 0)
        exit(1);
}

