/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:31 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 12:06:14 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int rgb_to_hex(t_rgb rgb)
{
    return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

void    draw_game(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.line_len, &game->img.endian);
    draw_floor_ceiling(game);
    ft_ray_casting(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void    draw_floor_ceiling(t_game *game)
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

void    draw_line(t_game *game, int w, float dist) //dist -> distance from player to projection plane
{
    unsigned int *dst; // destination
    unsigned int *src; // source
    unsigned int h; // projection plane height
    float src_factor; // source factor for texture
    float dst_shift; // destination shift for texture (texture height / projection plane height)

    h  = (float)HEIGHT / dist; // projection plane height, if dist is bigger, h is smaller
    src_factor = 0.0f;
    dst_shift = (float)game->txt[game->txt_index].height / h; // destination shift for texture = texture height / projection plane height
    if (h > HEIGHT) // if projection plane height is bigger than screen height
    {
        src_factor = 0.5f * (h - HEIGHT) / (h * game->txt[game->txt_index].height); // source factor for texture = 0.5 * (projection plane height - screen height) / (projection plane height * texture height)
        h = HEIGHT; // projection plane height = screen height
    }
    src = (unsigned int *)game->txt[game->txt_index].addr; // source = texture address
    src += (int)((float)game->txt_width * game->txt[game->txt_index].width); // source += texture width * texture height
    dst = (unsigned int *)game->img.addr + w + (HEIGHT - h) / 2 * WIDTH; // destination = image address + w + (screen height - projection plane height) / 2 * screen width
    while (h-- > 0) // while projection plane height is bigger than 0
    {
        *dst = *(src + ((int)src_factor) * game->txt[game->txt_index].width); // destination = source + (int)source factor * texture width
        dst += WIDTH; // destination += screen width
        src_factor += dst_shift; // source factor += destination shift
    }
}