/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_map_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:10:07 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:57 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img_player(t_data *data, t_point point)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img_p, point.x,
		point.y);
}

void	img_walls(t_data *data, t_point point)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img_1, point.x,
		point.y);
}

void	img_empty_space(t_data *data, t_point position)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img_0, position.x,
		position.y);
}

void	img_door(t_data *data, t_point position)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img_e, position.x,
		position.y);
}

void	img_collectable(t_data *data, t_point position)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img_c, position.x,
		position.y);
}
