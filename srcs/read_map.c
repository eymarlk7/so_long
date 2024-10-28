#include "../include/so_long.h"

int ft_open_file(char *argv)
{
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd == -1)
        return (-1);
    return (fd);
}

char    *ft_read_map(int fd)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *map;
    char    *tmp;
    size_t  bytes_read;

    bytes_read = 0;
    map = (char *)malloc(sizeof(buffer));
    if (!map)
    {
        free(map);
        return NULL;
    }
    map[0] = '\0';
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        tmp = ft_strjoin(map, buffer);
        free(map);
        map = tmp;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    return (map);
}

char    **ft_get_map(char *map_path)
{
    int fd;
    char    **matrix;
    char    *map;

    fd = ft_open_file(map_path);
    if (fd == -1)
    {
        ft_putstr_fd("Error\nmap is not valid\n", 2);
        exit(1);
    }
    map = ft_read_map(fd);
    matrix = ft_split(map, '\n');
    free(map);
    return (matrix);
}
