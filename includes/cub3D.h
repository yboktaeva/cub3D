/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:31:33 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 17:08:25 by yuboktae         ###   ########.fr       */
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
void    init_struct(t_game *game);
void    init_window(t_game *game);
void    check_args(int argc, char **argv);
void    init_data(t_data *data);
void    init_trgb(t_rgb *trgb);
void    init_img(t_img *img);
/*
 **PARSE
 */
int     get_fileline(char *file, t_game *game);
void    get_file(char *path, t_game *game);
void	get_line(t_game *game, int i, int j, int fd);
void    parse_cub(t_game *game, char *map_name);
int     is_texture(char **strs);
int     is_color(char **strs);
int     valid_color(char **strs);
void	get_map(t_game *game);
void    get_texture(t_game *game);
void    get_color(t_game *game);
void    open_texture(t_game *game);
void    xpm_file(t_game *game);
void    *check_ceiling(t_game *game, char *str);
void    *check_floor(t_game *game, char *str);
int     ft_isspace(char c);
/*
 **IMAGE
 */
int     rgb_to_hex(t_rgb rgb);
void    draw_game(t_game *game);
void    draw_floor_ceiling(t_game *game);
//draw wall function (raycasting);
/*
 **GAME
 */
void    start_game(t_game *game);
void    draw_floor_ceiling(t_game *game);
/*
 **EVENTS
 */
int     close_game(t_game *game);
int     key_press(int keysym, t_game *game);
/*
 **FREE
 */
void    destroy_game(t_game *game);
void	file_failure(t_game *game, char *msg);
void	free_line(char **line);
void	free_data(t_data *data);
/*
 **UTILS
 */
void    ft_error(char *str);

#endif
