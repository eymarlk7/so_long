/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: playboy7xb <playboy7xb@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:57:20 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:17 by playboy7xb       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_first_line_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\n' && argv[i + 1] == '\n')
			return (-1);
		i++;
	}
	if (argv[i] == '\0' && argv[i - 1] == '\n')
		return (-1);
	return (0);
}

int	ft_open_file(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

char	*ft_read_map(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*map;
	char	*tmp;
	size_t	bytes_read;

	bytes_read = 0;
	map = (char *)malloc(sizeof(buffer));
	if (!map)
	{
		free(map);
		return (NULL);
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

char	**ft_get_map(char *map_path)
{
	int		fd;
	char	**matrix;
	char	*map;

	fd = ft_open_file(map_path);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nmap is not valid\n", 2);
		exit(1);
	}
	map = ft_read_map(fd);
	if (ft_first_line_empty(map) != 0)
	{
		ft_putstr_fd("Error\nThe map is empty or has invalid character\n", 2);
		free(map);
		exit(1);	
	}
	matrix = ft_split(map, '\n');
	free(map);
	return (matrix);
}
