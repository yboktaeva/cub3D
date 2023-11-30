/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:31:33 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/30 15:17:31 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "struct.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>

/*
 **INIT
 */
void	init_struct(t_game *game);
void	init_img(t_img *img);
void	check_args(char **argv);
void	init_data(t_data *data);
void	init_trgb(t_rgb *trgb);
void	init_txt(t_txt *txt);
void	init_map(t_map *map);
void	init_texture_files(t_game *game);
void	init_window(t_game *game);
/*
 **PARSE
 */
int		get_fileline(char *file, t_game *game);
void	get_file(char *path, t_game *game);
void	get_line(t_game *game, int i, int j, int fd);
void	parse_cub(t_game *game, char *map_name);
int		is_texture(char **strs);
int		is_color(char **strs);
int		map_line(char **file, int i);
ssize_t	length_line(char *line_map);
void	copy_into(t_data *data, char *map_line, int x);
void	map_into_data(int line, t_game *game, char **map);
int		check_elements(char **map);
int		dfs(char **map, int i, int j, t_data *data);
int		map_isclosed(char **map, t_data *data);
void	parse_map(t_game *game);
void	get_map(t_game *game);
void	get_texture(t_game *game, int i);
void	get_color(t_game *game);
void	*check_ceiling(t_game *game, char *str);
void	*check_floor(t_game *game, char *str);
void	check_file(char **map, t_game *game);
void	direction(char **map, int i, int j, t_game *game);
int		is_fcvalid(char *str, char c);
int		skip_spacecomma(int i, char *str, t_game *game);
void	only_onemap(char **file, t_game *game);
int		color_loop(t_game *game, char *str, char c, int floor);

/*
 **IMAGE
 */
int		rgb_to_hex(t_rgb rgb);
void	draw_game(t_game *game);
void	draw_floor_ceiling(t_game *game);
void	draw_line(t_game *game, int w, float dist);
float	ft_ray(t_game *game, float angle);
void	ft_ray_casting(t_game *game);
/*
 **GAME
 */
void	start_game(t_game *game);
void	ft_move(t_game *game, int direction);
void	find_position(t_game *game);
/*
 **EVENTS
 */
int		close_game(t_game *game);
int		key_press(int keysym, t_game *game);
/*
 **FREE
 */
void	destroy_game(t_game *game);
void	file_failure(t_game *game, char *msg);
void	free_line(char **line);
void	free_data(t_data *data);
void	free_texture(t_game *game);
/*
 **UTILS
 */
void	ft_error(char *str);
int		ft_isspace(char c);
int		empty_line(char *str, int space);
float	ft_sign(float n);
int		str_digit(char *str);
void	if_exist(t_game *game, int f);
int		init_path_nswe(t_game *game);

#endif
