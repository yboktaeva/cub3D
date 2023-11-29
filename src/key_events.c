/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:36:38 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 11:50:36 by yuboktae         ###   ########.fr       */
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
	else if (keysym == ARROW_LEFT) //rotate left
		game->map.view_angle -= 0.02f * M_PI; // 0.02 * 180 degree
	else if (keysym == ARROW_RIGHT) //rotate right
		game->map.view_angle += 0.02f * M_PI; // 0.02 * 180 degree
	else if (keysym == KEY_A) // move left
		ft_move(game, 3); // 3 means left
	else if (keysym == KEY_D) // move right
		ft_move(game, 1); // 1 means right
	else
		return (0);
	mlx_destroy_image(game->mlx, game->img.img);
	draw_game(game);
	return (0);
}

void	ft_move(t_game *game, int direction)
{
	float	dist; // distance from player to wall
	float	dist_x; // distance from player to wall horizontally
	float	dist_y; // distance from player to wall vertically
	float	angle; // angle between player and wall
	
	angle = game->map.view_angle + direction * M_PI / 2; // angle between player and wall = player angle + direction * 90 degree
	dist_x = 0.1f * cos(angle); // distance from player to wall horizontally = 0.1 * cos(angle)
	dist_y = 0.1f * sin(angle); // distance from player to wall vertically = 0.1 * sin(angle)
	dist = ft_ray(game, ft_sign(dist_y) * M_PI / 2); // distance from player to wall = ray casting
	if (dist * dist < dist_y * dist_y) 
		dist_y = 0.0f; // if there is a wall, then the distance is 0 vertically
	dist = ft_ray(game, (1 - (ft_sign(dist_x) + 1) / 2) * M_PI);
	if (dist * dist < dist_x * dist_x)
		dist_x = 0.0f; // if there is a wall, then the distance is 0 horizontally
	dist = ft_ray(game, angle); // if there is a wall, then the distance is 0 diagonally (angle between player and wall)
	if (dist * dist < dist_x * dist_x + dist_y * dist_y) // if there is a wall, then the distance is 0 diagonally
	{
		if (ft_sign(dist_y) * ft_sign(dist_x) != 0) // if there is a wall, then the distance is 0 diagonally
			dist_y = 0.0f;
	}
	game->map.pos_x += dist_x; // player position += distance from player to wall horizontally
	game->map.pos_y += dist_y; // player position += distance from player to wall vertically
}