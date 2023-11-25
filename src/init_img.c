/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 18:06:49 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h" 

void    init_img(t_img *img)
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

void   init_txt(t_txt *txt)
{
    txt = (t_txt *)malloc(sizeof(t_txt) * 4);
    txt->path_nswe = NULL;
    txt->img = NULL;
    txt->addr = NULL;
    txt->bpp = 0;
    txt->endian = 0;
    txt->line_len = 0;
    txt->width = 0;
    txt->height = 0;
}

void	init_data(t_data *data)
{
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->map = NULL;
	data->ceiling_color = 0;
	data->floor_color = 0;
}

void    init_struct(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->file = NULL;
    game->txt_index = 0;
    init_img(&game->img);
    init_txt(game->txt);
	init_data(&game->data);
	init_trgb(&game->ceiling);
	init_trgb(&game->floor);
}