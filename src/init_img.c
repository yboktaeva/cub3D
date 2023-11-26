/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:41:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/26 13:01:29 by yuboktae         ###   ########.fr       */
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
    int i;
    game->mlx = NULL;
    game->win = NULL;
    game->file = NULL;
    game->txt_index = 0;
    game->txt_width = 0;
    game->txt_height = 0;
    init_img(&game->img);
    if ((game->txt = (t_txt *)malloc(sizeof(t_txt) * 4)) == NULL)
        file_failure(game, "malloc failed for txt");
    init_txt(game->txt);
    i = -1;
    game->path_nswe = NULL;
    while (++i < 4)
    {
        //game->path_nswe[i] = NULL;
        game->txt[i].img = NULL;
        game->txt[i].addr = NULL;
    }
	init_data(&game->data);
	init_trgb(&game->ceiling);
	init_trgb(&game->floor);
}