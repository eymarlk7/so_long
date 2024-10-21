#include "so_long.h"

int main(void)
{
    t_data  data;

    int fd = open("./my.txt", O_RDONLY);
    char *str = get_next_line(fd);
    data.map = ft_split(str, '\n');
    ft_check_map(data.map);

    return 0;
}