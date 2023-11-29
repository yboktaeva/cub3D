/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:09:31 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 18:34:30 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*Function draw_line draws a line on the screen using distance 
 * from player to projection plane and texture by using source 
 * factor and destination shift for texture and destination 
 * shift for screen if distance is bigger, projection plane height 
 * is smaller, so source factor is bigger and destination shift is smaller*/

int	rgb_to_hex(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

void	draw_game(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	draw_floor_ceiling(game);
	ft_ray_casting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	draw_floor_ceiling(t_game *game)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *)game->img.addr;
	i = WIDTH * HEIGHT / 2 + 1;
	while (--i > 0)
		*dst++ = game->data.ceiling_color;
	i = WIDTH * HEIGHT / 2 + 1;
	while (--i > 0)
		*dst++ = game->data.floor_color;
}

void	draw_line(t_game *game, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_factor;
	float			dst_shift;

	h = (float)HEIGHT / dist;
	src_factor = 0.0f;
	dst_shift = (float)game->txt[game->txt_index].height / h;
	if (h > HEIGHT)
	{
		src_factor = 0.5f * (h - HEIGHT) * dst_shift;
		h = HEIGHT;
	}
	src = (unsigned int *)game->txt[game->txt_index].addr;
	src += (int)((float)game->txt_width * game->txt[game->txt_index].width);
	dst = (unsigned int *)game->img.addr + w + (HEIGHT - h) / 2 * WIDTH;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_factor) * game->txt[game->txt_index].width);
		dst += WIDTH;
		src_factor += dst_shift;
	}
}
