#include "so_long.h"

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 65307)
        {
                free(data->map);
                free(data->window);
                free(data->mlx);
                exit(0);
        }
	return (0);
}
void    handler_hooks(t_data data)
{
        mlx_hook(data.window, KeyRelease, KeyReleaseMask, &on_keypress, &data);
        mlx_hook(data.window, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
}