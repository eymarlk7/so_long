/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:15:00 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:15:02 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

char	**get_map(char *map_path)
{
	int		fd;
	char	*map_str;
	char	**split;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	map_str = get_next_line(fd);
	split = ft_split(map_str, '\n');
	free(map_str);
	return (split);
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
