/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 15:35:02 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h" 

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->line_len = 0;
	img->img_width = 0;
	img->img_height = 0;
}

void	init_trgb(t_rgb *trgb)
{
	trgb->r = 0;
	trgb->g = 0;
	trgb->b = 0;
}

void	init_txt(t_txt *txt)
{
	txt->img = NULL;
	txt->bpp = 0;
	txt->endian = 0;
	txt->line_len = 0;
	txt->width = 0;
	txt->height = 0;
}

void	init_data(t_data *data)
{
	data->ceiling_color = 0;
	data->floor_color = 0;
	data->map = NULL;
	data->map_line = 0;
	data->row_max = 0;
}

void	init_map(t_map *map)
{
	map->pos_x = 0;
	map->pos_y = 0;
	map->dir_x = 0;
	map->dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	map->map_x = 0;
	map->map_y = 0;
	map->step_x = 0;
	map->step_y = 0;
}
