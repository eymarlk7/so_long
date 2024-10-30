/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:56:46 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 17:08:20 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_img_path(char *mlx, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->img_0 = mlx_xpm_file_to_image(mlx, "./textures/img_0.xpm", &x, &y);
	img->img_1 = mlx_xpm_file_to_image(mlx, "./textures/img_1.xpm", &x, &y);
	img->img_c = mlx_xpm_file_to_image(mlx, "./textures/img_c.xpm", &x, &y);
	img->img_e = mlx_xpm_file_to_image(mlx, "./textures/img_e.xpm", &x, &y);
	img->img_p_right = mlx_xpm_file_to_image(mlx, "./textures/img_p0.xpm", &x,
			&y);
	img->img_p_left = mlx_xpm_file_to_image(mlx, "./textures/img_p1.xpm", &x,
			&y);
}

void	print_image(t_game *game, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_1, w, h);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_0, w, h);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_c, w, h);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.img_e, w, h);
	if (c == 'P')
	{
		if (game->control == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img.img_p_right,
				w, h);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img.img_p_left,
				w, h);
	}
}

void	print_map_window(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->posix.x = 0;
	game->posix.y = 0;
	while (game->map[++i])
	{
		j = -1;
		game->posix.x = 0;
		while (game->map[i][++j])
		{
			print_image(game, game->map[i][j], game->posix.x, game->posix.y);
			game->posix.x += 33;
		}
		game->posix.y += 33;
	}
}

void	get_init_mlx(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	game->map = argv;
}

void	ft_init_game(char **argv)
{
	t_game	game;

	get_init_mlx(&game, argv);
	game.count_step = 0;
	game.count_ch = 0;
	game.control = 0;
	get_img_path(game.mlx, &game.img);
	game.win = mlx_new_window(game.mlx, ft_strlen(argv[1]) * 33, len_row(argv)
			* 33, "SO LONG");
	mlx_hook(game.win, 02, 1L << 0, keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	print_map_window(&game);
	mlx_loop(game.mlx);
}
