/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:27:24 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/27 17:45:14 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1280
# define HEIGHT 1280

typedef struct s_map
{
	double pos_x;   // player position
	double pos_y;   // player position
	double dir_x;   // player direction
	double dir_y;   // player direction
	double plane_x; // camera plane
	double plane_y; // camera plane
	int map_x;      // map position
	int map_y;      // map position
	int step_x;     // step and side dist
	int step_y;     // step and side dist
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_txt
{
    void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}           t_txt;

typedef struct s_data
{
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char	**map;
	int	map_line; //w
	int row_max; //h
}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**file;
    char    **path_nswe;
    int     txt_index;
	int		txt_width;
	int		txt_height;
	t_img	img;
	t_map	map;
	t_data	data;
    t_rgb   floor;
    t_rgb   ceiling;
    t_txt   *txt;
}			t_game;

#endif
