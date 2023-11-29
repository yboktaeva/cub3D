/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:36:38 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 18:09:48 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_game(t_game *game)
{
	destroy_game(game);
	exit(0);
}

int	key_press(int keysym, t_game *game)
{
	if (game->win == NULL)
		return (1);
	if (keysym == XK_Escape || keysym == XK_q || keysym == XK_Q)
	{
		destroy_game(game);
		exit(0);
	}
	else if (keysym == ARROW_UP || keysym == KEY_W)
		ft_move(game, 0);
	else if (keysym == ARROW_DOWN || keysym == KEY_S)
		ft_move(game, 2);
	else if (keysym == ARROW_LEFT)
		game->map.view_angle -= 0.02f * M_PI;
	else if (keysym == ARROW_RIGHT)
		game->map.view_angle += 0.02f * M_PI;
	else if (keysym == KEY_A)
		ft_move(game, 3);
	else if (keysym == KEY_D)
		ft_move(game, 1);
	else
		return (0);
	mlx_destroy_image(game->mlx, game->img.img);
	draw_game(game);
	return (0);
}

void	ft_move(t_game *game, int direction)
{
	float	dist;
	float	dist_x;
	float	dist_y;
	float	angle;

	angle = game->map.view_angle + direction * M_PI / 2;
	dist_x = 0.1f * cos(angle);
	dist_y = 0.1f * sin(angle);
	dist = ft_ray(game, ft_sign(dist_y) * M_PI / 2);
	if (dist * dist < dist_y * dist_y)
		dist_y = 0.0f;
	dist = ft_ray(game, (1 - (ft_sign(dist_x) + 1) / 2) * M_PI);
	if (dist * dist < dist_x * dist_x)
		dist_x = 0.0f;
	dist = ft_ray(game, angle);
	if (dist * dist < dist_x * dist_x + dist_y * dist_y)
	{
		if (ft_sign(dist_y) * ft_sign(dist_x) != 0)
			dist_y = 0.0f;
	}
	game->map.pos_x += dist_x;
	game->map.pos_y += dist_y;
}
