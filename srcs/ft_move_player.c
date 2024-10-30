/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: playboy7xb <playboy7xb@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:57:01 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 13:52:33 by playboy7xb       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_steps(t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->count_step, 1);
	ft_putchar_fd('\n', 1);
}

void	last_step(t_game *game)
{
	game->count_step++;
	count_steps(game);
	close_game(game);
}

void	ft_move_other_pos(t_game *game, t_point begin, int y, int x)
{
	char	move;

	game->count_ch = find_char(game->map, 'C');
	move = game->map[begin.y + y][begin.x + x];
	if (move == 'C')
		game->count_ch++;
	if (move != '1')
	{
		if (move == 'E')
		{
			if (game->count_ch == 0)
				last_step(game);
			else
				return ;
		}
		else
		{
			game->map[begin.y][begin.x] = '0';
			game->map[begin.y + y][begin.x + x] = 'P';
		}
		game->count_ch++;
		game->count_step++;
		count_steps(game);
		print_map_window(game);
	}
}

int	keypress(int key, t_game *game)
{
	game->posix = find_posix(game->map, 'P');
	if (key == 'a' || key == 65361)
	{
		game->control = 1;
		ft_move_other_pos(game, game->posix, 0, -1);
	}
	if (key == 'd' || key == 65363)
	{
		game->control = 0;
		ft_move_other_pos(game, game->posix, 0, 1);
	}
	if (key == 's' || key == 65364)
	{
		ft_move_other_pos(game, game->posix, 1, 0);
	}
	if (key == 'w' || key == 65362)
	{
		ft_move_other_pos(game, game->posix, -1, 0);
	}
	if (key == 65307)
		close_game(game);
	return (1);
}
