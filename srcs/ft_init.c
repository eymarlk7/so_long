/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:54:16 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:30 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_position(t_point *position)
{
	position->x = 0;
	position->y = 0;
}

t_point	ft_position(t_point position)
{
	init_position(&position);
	return (position);
}

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

void	initiate_struct(t_data *data, char **map)
{
	data->map = map;
	data->count = 0;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 33 * map_len_x(data->map[0]), 33
			* map_len_y(data->map), "So_long");
	init_items(data);
}
