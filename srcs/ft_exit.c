/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: playboy7xb <playboy7xb@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:56:39 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/30 14:41:15 by playboy7xb       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

// void	ft_free_str(char *argv)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		free(argv);
// 		i++;
// 	}
// 	free(argv);
	
// }