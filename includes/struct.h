/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:27:24 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 17:18:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1280
# define HEIGHT 1280
# define M_PI 3.14159265358979323846
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	float	view_angle;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
}	t_map;

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	int		step_x;
	int		step_y;
	float	vert_x;
	float	vert_y;
	float	horz_y;
	float	horz_x;
	float	vert_dist;
	float	horz_dist;
	float	vert_w;
	float	horz_w;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}	t_txt;

typedef struct s_data
{
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			**map;
	int				map_line;
	int				row_max;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**file;
	char	**path_nswe;
	int		txt_index;
	float	txt_width;
	float	txt_height;
	t_img	img;
	t_map	map;
	t_ray	ray;
	t_data	data;
	t_rgb	floor;
	t_rgb	ceiling;
	t_txt	*txt;
}	t_game;

#endif
