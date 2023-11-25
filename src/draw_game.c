/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:31 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 16:21:31 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int rgb_to_hex(t_rgb rgb)
{
    return (rgb.r << 16 | rgb.g << 8 | rgb.b);
    //return (256 * 256 * rgb.r + 256 * rgb.g + rgb.b);
}

void    draw_game(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.line_len, &game->img.endian);
    draw_floor_ceiling(game);
    //ray_cast(game) (raycasting)
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
    //mlx_destroy_image(game->mlx, game->img.img);
}

void    draw_floor_ceiling(t_game *game) //not sure for this function
{
    unsigned int *dst;
    unsigned int i;

    dst = (unsigned int *)game->img.addr;
    i = WIDTH * HEIGHT / 2 + 1;
    while (--i > 0)
        *dst++ = game->data.ceiling_color;
    i = WIDTH * HEIGHT / 2 + 1;
    while (--i > 0)
        *dst++ = game->data.floor_color;
}

// void    draw_wall(t_game *game, int w, float dist)
// {
//     unsigned int *dst;
//     unsigned int *src;
//     unsigned int h;
//     float src_factor;
//     float dst_shift;

//     h  = (float)HEIGHT / dist;
//     src_factor = 0.0f;
//     dst_shift = (float)
// }