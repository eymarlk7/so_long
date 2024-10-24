/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:51 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:11:48 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	char	**map1;
	int		status;
	t_data	data;

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
	print_map(map, &data, (t_point){0, 0});
	mlx_key_hook(data.window, start_player, &data);
	mlx_loop(data.mlx);
	return (0);
}
