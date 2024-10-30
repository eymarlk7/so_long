/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: playboy7xb <playboy7xb@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:57:20 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 15:01:11 by playboy7xb       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_first_line_empty(char *argv)
{
	if (*argv == '\0' || *argv == '\n')
	{
		ft_putstr_fd("Error\nfirst line is empty or has invalid character\n", 2);
		free(argv);
		exit(1);
	}
	if (*argv == ' ' || *argv == '\t' 
	|| (*argv >= 9 && *argv <= 13))
	{
		ft_putstr_fd("Error\nfirst line is empty or has invalid character\n", 2);
		free(argv);
		exit(1);
	}		
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
	ft_first_line_empty(map);
	matrix = ft_split(map, '\n');
	free(map);
	return (matrix);
}
