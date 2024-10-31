/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:56:01 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/31 16:42:52 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_line_empty(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '\0' || argv[i] == '\n')
		return (-1);
	while (argv[i])
	{
		if (argv[i] == '\n' && argv[i + 1] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	check_map_char(char **map)
{
	int	y;
	int	x;

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
				ft_putstr_fd("Error\nAn invalid character was found in the map\n",
					2);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	has_main_char(char **map)
{
	if (find_char(map, 'P') < 1 || find_char(map, 'E') < 1)
	{
		ft_putstr_fd("Error\nthere is no player or exit on the map\n", 2);
		return (-1);
	}
	else if (find_char(map, 'P') > 1 || find_char(map, 'E') > 1)
	{
		ft_putstr_fd("Error\nthere are too many player or exit on the map\n",
			2);
		return (-1);
	}
	else if (find_char(map, 'C') < 1)
	{
		ft_putstr_fd("Error\nthere are no collectibles on the map\n", 2);
		return (-1);
	}
	return (0);
}

void	ft_check_all(char *path, char **map)
{
	if (ft_check_extension(path) == -1)
		ft_error_to_exit(map);
	else if (check_rows(map) == -1)
		ft_error_to_exit(map);
	else if (map_around_walls(map) == -1)
		ft_error_to_exit(map);
	else if (has_main_char(map))
		ft_error_to_exit(map);
	else if (check_map_char(map) == -1)
		ft_error_to_exit(map);
	else if (check_size_map(map) == -1)
		ft_error_to_exit(map);
	valid_path(map);
}
