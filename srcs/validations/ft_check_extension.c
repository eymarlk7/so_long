/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:55:51 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 19:25:59 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*cpy_name_path(char *argv)
{
	char	*name_path;

	name_path = ft_strchr(argv, '/');
	if (name_path == NULL)
		name_path = argv;
	if (*name_path == '/')
		name_path++;
	return (name_path);
}

int	ft_check_extension(char *argv)
{
	char	*name_path;
	char	*cpy_name_extension;

	cpy_name_extension = '\0';
	name_path = cpy_name_path(argv);
	cpy_name_extension = ft_strrchr(name_path, '.');
	if (cpy_name_extension == NULL)
		cpy_name_extension = name_path;
	if (ft_strlen(name_path) > 4)
	{
		if (ft_strcmp(cpy_name_extension, ".ber") != 0)
		{
			ft_putstr_fd("Error\nthis map is not valid extension error\n", 2);
			return (-1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nthis map is not valid extension error\n", 2);
		return (-1);
	}
	return (0);
}
