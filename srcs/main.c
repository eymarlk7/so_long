#include "../include/so_long.h"

int main(int argc, char **argv)
{
    char **map;
    char **cpy_map;

    if (argc != 2)
        return (0);
    if (ft_check_extension(argv[1]) == -1)
        exit(1);
    cpy_map = ft_get_map(argv[1]);
    ft_check_all(argv[1], cpy_map);
    map = ft_get_map(argv[1]);
    ft_init_game(map);
    return 0;
}


