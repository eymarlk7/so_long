/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:15:00 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 19:04:36 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	int	status;

	status = map_extension(map_path);
	if (status != 0)
	{
		check_status(status);
		exit(1);
	}
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nThe map does not exist\n");
		exit(1);
	}
	map_str = ft_read_str(fd);
	split = ft_split(map_str, '\n');
	free(map_str);
	return (split);
}
