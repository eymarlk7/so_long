/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:56:10 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/28 16:47:58 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_path(char **map, t_point pos, t_point begin, char ch)
{
	if (map[pos.y][pos.x] == '1')
		return ;
	if (map[pos.y][pos.x] == ch)
		return ;
	map[pos.y][pos.x] = ch;
	ft_check_path(map, (t_point){(pos.y + 1), pos.x}, begin, ch);
	ft_check_path(map, (t_point){(pos.y - 1), pos.x}, begin, ch);
	ft_check_path(map, (t_point){pos.y, (pos.x + 1)}, begin, ch);
	ft_check_path(map, (t_point){pos.y, (pos.x - 1)}, begin, ch);
}

void	valid_path(char **cpy_map)
{
	char	**cpy1;
	t_point	posix;
	t_point	posix_e;
	int		count_c;

	cpy1 = cpy_map;
	count_c = 0;
	posix = find_posix(cpy_map, 'P');
	posix_e = find_posix(cpy_map, 'E');
	cpy_map[posix_e.y][posix_e.x] = '1';
	ft_check_path(cpy_map, posix, posix, '-');
	count_c += find_char(cpy_map, 'C');
	count_c += find_char(cpy_map, 'E');
	cpy_map[posix_e.y][posix_e.x] = 'E';
	ft_check_path(cpy1, posix, posix, 'x');
	count_c += find_char(cpy1, 'C');
	count_c += find_char(cpy1, 'E');
	if (count_c != 0)
	{
		ft_putstr_fd("Error\npath invalid\n", 2);
		ft_free(cpy_map);
		exit(1);
	}
	ft_free(cpy_map);
}
