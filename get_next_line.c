#include "so_long.h"

static char	*dupline(char *src)
{
	char	*str;
	int		i;

	i = -1;
	while (src[++i])
		;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	rd[BUFFER_SIZE];
	char		line[7000000];
	static int	lido, pos;
	int		i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= lido)
		{
			lido = read(fd, rd, BUFFER_SIZE);
			pos = 0;
			if (lido <= 0)
				break ;
		}
		line[i++] = rd[pos++];
		if (line[i - 1] == '\0')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (dupline(line));
}