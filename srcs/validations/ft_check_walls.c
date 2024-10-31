/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:56:17 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/31 15:46:58 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_walls(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (-1);
		x++;
	}
	while (map[y])
	{
		if (map[y][0] != '1')
			return (-1);
		y++;
	}
	return (0);
}

static int	ft_walls2(char **map)
{
	int		y;
	size_t	x;

	y = len_row(map);
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1')
			return (-1);
		x++;
	}
	x = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		if (map[y][x - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	map_around_walls(char **map)
{
	if (ft_walls(map) == -1 || ft_walls2(map) == -1)
	{
		ft_putstr_fd("Error\nthe map is not between walls\n", 2);
		return (-1);
	}
	return (0);
}

int	check_size_map(char **map)
{
	int	len_widht;
	int	len_height;

	len_widht = ft_strlen(map[0]) * 33;
	len_height = len_row(map) * 33;
	if (len_height > 1023)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("the height game is greater than the main screen\n", 2);
		return (-1);
	}
	else if (len_widht > 1914)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("the widht game is greater than the main screen\n", 2);
		return (-1);
	}
	return (0);
}

int	check_rows(char **map)
{
	size_t	row;
	int		y;

	row = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != row)
		{
			ft_putstr_fd("Error\nthe map is not rectangular\n", 2);
			return (-1);
		}
		y++;
	}
	return (0);
}
