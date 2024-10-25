/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:13 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 19:01:58 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *argv)
{
	int	fd;

	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

char	*ft_read_str(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*result;
	size_t	bytes_read;

	result = (char *)malloc(sizeof(buffer));
	result[0] = '\0';
	if (!result)
		return (0);
	bytes_read = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}
