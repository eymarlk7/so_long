#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
	{
		if (tab[cur.y][cur.x] == '0')
			tab[cur.y][cur.x] = '-';
		else if (tab[cur.y][cur.x] == 'C')
			tab[cur.y][cur.x] = '-';
		// else if (tab[cur.y][cur.x] == 'E')
		// 	tab[cur.y][cur.x] = '-';
		else if (tab[cur.y][cur.x] == 'P')
			tab[cur.y][cur.x] = '-';
		else
			return ;
	}
	tab[cur.y][cur.x] = '-';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

t_point find_player(char **map)
{
        t_point posion;

        posion.x = 0;
        posion.y = 0;
        while (map[posion.y])
        {
                posion.x = 0;
                while (map[posion.y][posion.x])
                {
                        if (map[posion.y][posion.x] == 'P')
                                return (posion);
                        posion.x++;
                }
                posion.y++;
        }
        posion.x = 0;
        posion.y = 0;
        return (posion);
}

int    check_path(char **map)
{
        int     count;
        t_point size;
        t_point posion;

        count                   = 0;
        posion = find_player(map);
        size.x = map_len_x(map[0]);
        size.y = map_len_y(map);
        flood_fill(map, size, posion);
        count += find_char(map, 'C');
        // count += find_char(map, 'E');
        count += find_char(map, 'P');
        if (count != 0)
        {
                write(2, "Error\n", 6);
                return (-1);             
        }
        return (0);
}