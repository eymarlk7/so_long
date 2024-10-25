/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:19:05 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:04:35 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*window;
	void	*img_c;
	void	*img_p;
	void	*img_1;
	void	*img_0;
	void	*img_e;
	int		count;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

// teste

t_point		find_player(char **map);
void		init_items(t_data *data);
t_point		ft_position(t_point position);
void		init_position(t_point *position);
void		initiate_struct(t_data *data, char **map);

char		*ft_read_str(int fd);
char		**get_map(char *map_path);

int			check_dup(char **map);
int			map_len_x(char *line);
int			map_len_y(char **map);
int			check_path(char **map);
int			check_line(char **map);
int			check_walls(char **map);
int			on_destroy(t_data *data);
int			check_walls2(char **map);
int			map_extension(char *map);
int			check_map_args(char **map);
int			check_rectangle(char **map);
int			find_char(char **map, char c);
int			ft_exit(int keysym, t_data *data);
int			ft_check_map(char *path, char **map);
int			start_player(int keysym, t_data *data);

void		check_status(int nbr);
void		img_walls(t_data *data, t_point point);
void		img_player(t_data *data, t_point point);
void		img_door(t_data *data, t_point position);
void		ft_mov_player_up(t_data *data, t_point *player);
void		img_collectable(t_data *data, t_point position);
void		img_empty_space(t_data *data, t_point position);
void		ft_mov_player_down(t_data *data, t_point *player);
void		ft_mov_player_left(t_data *data, t_point *player);
void		ft_mov_player_right(t_data *data, t_point *player);
void		print_map(char **map, t_data *data, t_point point);

#endif