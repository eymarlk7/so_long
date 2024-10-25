/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:56 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:12:12 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map, t_data *data, t_point position)
{
	t_point	matrix;

	init_position(&matrix);
	while (map[matrix.y])
	{
		matrix.x = 0;
		position.x = 0;
		while (map[matrix.y][matrix.x])
		{
			if (map[matrix.y][matrix.x] == '1')
				img_walls(data, position);
			else if (map[matrix.y][matrix.x] == '0')
				img_empty_space(data, position);
			else if (map[matrix.y][matrix.x] == 'P')
				img_player(data, position);
			else if (map[matrix.y][matrix.x] == 'E')
				img_door(data, position);
			else if (map[matrix.y][matrix.x] == 'C')
				img_collectable(data, position);
			position.x += 33;
			matrix.x++;
		}
		position.y += 33;
		matrix.y++;
	}
}
