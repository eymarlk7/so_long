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

	int	count = find_char(game->map, 'C');
	move = game->map[begin.y + y][begin.x + x];
	if (move == 'C')
		count++;
	if (move != '1')
	{
		if (move == 'E')
		{
			if (count == 0)
				last_step(game);
			else
				return ;
		}
		else
		{
			game->map[begin.y][begin.x] = '0';
			game->map[begin.y + y][begin.x + x] = 'P';
		}
		count++;
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
		ft_move_other_pos(game, game->posix, 0, -1);
	}
	if (key == 'd' || key == 65363)
	{
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
