/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:56 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:34:29 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	init_items(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	data->img_1 = mlx_xpm_file_to_image(data->mlx, "textures/img_1.xpm", &width,
			&height);
	data->img_0 = mlx_xpm_file_to_image(data->mlx, "textures/img_0.xpm", &width,
			&height);
	data->img_e = mlx_xpm_file_to_image(data->mlx, "textures/img_e.xpm", &width,
			&height);
	data->img_p = mlx_xpm_file_to_image(data->mlx, "textures/img_p.xpm", &width,
			&height);
	data->img_c = mlx_xpm_file_to_image(data->mlx, "textures/img_c.xpm", &width,
			&height);
}

void	init_position(t_point *point)
{
	point->x = 0;
	point->y = 0;
}

void	print_map(char **map, t_data *data, t_point point)
{
	t_point	matrix;

	init_position(&matrix);
	while (map[matrix.y])
	{
		matrix.x = 0;
		point.x = 0;
		while (map[matrix.y][matrix.x])
		{
			if (map[matrix.y][matrix.x] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->img_1,
					point.x, point.y);
			else if (map[matrix.y][matrix.x] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->img_0,
					point.x, point.y);
			else if (map[matrix.y][matrix.x] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->img_p,
					point.x, point.y);
			else if (map[matrix.y][matrix.x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->img_e,
					point.x, point.y);
			else if (map[matrix.y][matrix.x] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->img_c,
					point.x, point.y);
			point.x += 33;
			matrix.x++;
		}
		point.y += 33;
		matrix.y++;
	}
}
