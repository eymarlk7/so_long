#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

int destroy_on(t_data *data)
{
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}

int on_keypress(int keysum, t_data *data)
{
    (void)data;
    if(keysum == 100)
    {
        move_right();
    }
    printf("Look: %d\n", keysum);
    return (0);
}

int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return(1);
    data.window = mlx_new_window(data.mlx, 540, 600, "Hello World");
    if (!data.window)
        return (free(data.window), 1);
    mlx_hook(data.window, KeyRelease, KeyReleaseMask, &on_keypress, &data);
    mlx_hook(data.window, DestroyNotify, StructureNotifyMask, &destroy_on, &data);

    mlx_loop(data.mlx);
    return 0;
}
x Y
0 0
1 0 
encon pos atual 