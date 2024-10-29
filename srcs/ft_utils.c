/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:57:07 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/28 17:41:21 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	len_row(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
	}
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

t_point	find_posix(char **map, char c)
{
	int		i;
	int		j;
	t_point	posix;

	j = 0;
	i = -1;
	posix.x = 0;
	posix.y = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
			{
				posix.x = j;
				posix.y = i;
				return (posix);
			}
		}
	}
	return (posix);
}
