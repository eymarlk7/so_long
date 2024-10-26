/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:58 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:27 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_1);
	mlx_destroy_image(data->mlx, data->img_p);
	mlx_destroy_image(data->mlx, data->img_c);
	mlx_destroy_image(data->mlx, data->img_e);
	mlx_destroy_image(data->mlx, data->img_0);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	exit(1);
}

int	ft_exit(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	return (0);
}
