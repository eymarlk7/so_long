#include "../include/so_long.h"

void	close_img(void *mlx, t_img *img)
{
	if (img->img_p)
		mlx_destroy_image(mlx, img->img_p);
	if (img->img_c)
		mlx_destroy_image(mlx, img->img_c);
	if (img->img_e)
		mlx_destroy_image(mlx, img->img_e);
	if (img->img_0)
		mlx_destroy_image(mlx, img->img_0);
	if (img->img_1)
		mlx_destroy_image(mlx, img->img_1);
}

int	window_close(t_game *game)
{
	ft_free(game->map);
	close_img(game->mlx, &game->img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

int	window_stop(t_game *game)
{
	ft_free(game->map);
	close_img(game->mlx, &game->img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

int	close_game(t_game *game)
{
	if (!window_close(game))
		exit(0);
	return (0);
}
