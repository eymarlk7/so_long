/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:15:00 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:23:56 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	map_len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_len_x(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	find_char(char **map, char c)
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
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}


char	**get_map(char *map_path)
{
	int		fd;
	char	*map_str;
	char	**split;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	map_str = get_next_line(fd);
	split = ft_split(map_str, '\n');
	free(map_str);
	return (split);
}
void	initiate_struct(t_data *data, char **map)
{
	data->map = map;
	data->count = 0;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 33 * map_len_x(data->map[0]), 33
			* map_len_y(data->map), "So_long");
	init_items(data);
}
