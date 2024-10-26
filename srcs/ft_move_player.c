/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:29 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:42 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_mov_player_right(t_data *data, t_point *player)
{
	t_point	position;

	*player = find_player(data->map);
	if (data->map[player->y][player->x + 1] != '1'
		&& data->map[player->y][player->x + 1] != 'E')
	{
		data->map[player->y][player->x] = '0';
		data->map[player->y][player->x + 1] = 'P';
		print_map(data->map, data, ft_position(position));
		data->count++;
		ft_printf("%d\n", data->count);
	}
	player->x++;
}

void	ft_mov_player_left(t_data *data, t_point *player)
{
	t_point	position;

	*player = find_player(data->map);
	if (data->map[player->y][player->x - 1] != '1'
		&& data->map[player->y][player->x - 1] != 'E')
	{
		data->map[player->y][player->x] = '0';
		data->map[player->y][player->x - 1] = 'P';
		print_map(data->map, data, ft_position(position));
		data->count++;
		ft_printf("%d\n", data->count);
	}
	player->x--;
}

void	ft_mov_player_up(t_data *data, t_point *player)
{
	t_point	position;

	*player = find_player(data->map);
	if (data->map[player->y - 1][player->x] != '1' && data->map[player->y
		- 1][player->x] != 'E')
	{
		data->map[player->y][player->x] = '0';
		data->map[player->y - 1][player->x] = 'P';
		print_map(data->map, data, ft_position(position));
		data->count++;
		ft_printf("%d\n", data->count);
	}
	player->y--;
}

void	ft_mov_player_down(t_data *data, t_point *player)
{
	t_point	position;

	*player = find_player(data->map);
	if (data->map[player->y + 1][player->x] != '1' && data->map[player->y
		+ 1][player->x] != 'E')
	{
		data->map[player->y][player->x] = '0';
		data->map[player->y + 1][player->x] = 'P';
		print_map(data->map, data, ft_position(position));
		data->count++;
		ft_printf("%d\n", data->count);
	}
	player->y++;
}
void ft_close_game(char **map, t_data *data)
{
	int	i = -1;

	ft_printf("Close\n");
	while (map[++i])
		free(map[i]);
	free(map);
	on_destroy(data);
	exit(0);
}

int	start_player(int keysym, t_data *data)
{
	t_point	player;

	player.y = 0;
	player.x = 0;
	ft_exit(keysym, data);
	if (keysym == 100)
		ft_mov_player_right(data, &player);
	else if (keysym == 97)
		ft_mov_player_left(data, &player);
	else if (keysym == 119)
		ft_mov_player_up(data, &player);
	else if (keysym == 115)
		ft_mov_player_down(data, &player);
	if (data->map[player.y][player.x] == 'E' && find_char(data->map, 'C') == 0)
	{
		data->count++;
		ft_printf("%d\n", data->count);
		ft_close_game(data->map, data);
	}
	return (0);
}
