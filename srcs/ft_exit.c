#include "../include/so_long.h"

void    ft_error(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    exit(1);
}

void    ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}