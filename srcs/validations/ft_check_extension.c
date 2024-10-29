/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:55:51 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/28 11:55:53 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_extension(char *argv)
{
	char	*cpy;
	char	*name_path;

	cpy = '\0';
	name_path = ft_strchr(argv, '/');
	if (name_path == NULL)
		name_path = argv;
	if (*name_path == '/')
		name_path++;
	cpy = ft_strchr(name_path, '.');
	if (ft_strlen(name_path) > 4)
	{
		if (ft_strcmp(cpy, ".ber") != 0)
		{
			ft_putstr_fd("Error\nthis map is not valid\n", 2);
			return (-1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nthis map is not valid\n", 2);
		return (-1);
	}
	return (0);
}
