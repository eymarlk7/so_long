/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:51 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 20:17:09 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// int ft_close(int keycode, t_data *data)
// {
// 	ft_printf("%d\n", keycode);
// 	mlx_destroy_window(data->mlx, data->window);
// 	exit(0);
// 	return (0);
// }

int	main(int ac, char **av)
{
	char	**map;
	char	**map1;
	int		status;
	t_data	data;
	t_point	position;

	if (ac != 2)
		return (0);
	map = get_map(av[1]);
	map1 = get_map(av[1]);
	status = ft_check_map(av[1], map1);
	if (status != 0)
	{
		check_status(status);
		free(map);
		free(map1);
		exit(1);
	}
	initiate_struct(&data, map);
	print_map(map, &data, ft_position(position));
	mlx_hook(data.window, 2, 1L<<0, start_player, &data);
	//mlx_key_hook(data.window, start_player, &data);
	mlx_loop(data.mlx);
	return (0);
}
