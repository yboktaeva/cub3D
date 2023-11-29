/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:03 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 18:33:55 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*Function ft_ray_casting use draw_line function to draw a line on the 
  screen from the player's position to the wall. The distance to the wall 
  is calculated by ft_ray function. The distance to the wall is multiplied 
  by cos(player's view angle - view angle) to avoid the fisheye effect.
  We don't use the distance to the wall directly because the distance to 
  the wall is calculated by the Pythagorean theorem, which is the hypotenuse 
  of the triangle. The wall hit is calculated by ft_ray function. 
  The vertcal wall hit and horizontal wall hit depend on the ray 
  direction and the player's position. If the ray direction is positive, 
  the vertical wall hit and horizontal wall hit are added 1 to avoid 
  the wall hit being the same as the player's position.*/

static void	ray_init(t_game *game, t_ray *ray, float angle)
{
	ray->dir_x = cos(angle);
	ray->dir_y = sin(angle);
	ray->step_x = ft_sign(ray->dir_x);
	ray->step_y = ft_sign(ray->dir_y);
	ray->vert_x = (int)game->map.pos_x;
	if (ray->step_x > 0)
		ray->vert_x += 1.0f;
	ray->horz_y = (int)game->map.pos_y;
	if (ray->step_y > 0)
		ray->horz_y += 1.0f;
}

static void	next_step_ray(t_game *game, t_ray *ray)
{
	if (ray->step_x != 0)
	{
		ray->vert_y = game->map.pos_y + ray->dir_y / ray->dir_x
			* (ray->vert_x - game->map.pos_x);
		ray->vert_dist = sqrt(pow(game->map.pos_x - ray->vert_x, 2.0)
				+ pow(game->map.pos_y - ray->vert_y, 2.0));
		ray->vert_w = ray->vert_y - (int)ray->vert_y;
		if (ray->step_x > 0)
			ray->vert_w = 1 - ray->vert_w;
	}
	else
		ray->vert_dist = INFINITY;
	if (ray->step_y != 0)
	{
		ray->horz_x = game->map.pos_x + ray->dir_x / ray->dir_y
			* (ray->horz_y - game->map.pos_y);
		ray->horz_dist = sqrt(pow(game->map.pos_x - ray->horz_x, 2.0)
				+ pow(game->map.pos_y - ray->horz_y, 2.0));
		ray->horz_w = ray->horz_x - (int)ray->horz_x;
		if (ray->step_y > 0)
			ray->horz_w = 1 - ray->horz_w;
	}
	else
		ray->horz_dist = INFINITY;
}

static float	save_color(t_game *game, float dist,
				int color_idx, float wall_hit)
{
	game->txt_index = color_idx;
	game->txt_width = wall_hit;
	return (dist);
}

float	ft_ray(t_game *game, float angle)
{
	t_ray	ray;

	ray_init(game, &ray, angle);
	while (1)
	{
		next_step_ray(game, &ray);
		if (ray.vert_dist < ray.horz_dist)
		{
			if (game->data.map[(int)ray.vert_y]
				[(int)ray.vert_x + (ray.step_x - 1) / 2] == '1')
				return (save_color(game, ray.vert_dist, ray.step_x + 1,
						ray.vert_w));
			else
				ray.vert_x += ray.step_x;
		}
		else
		{
			if (game->data.map[(int)ray.horz_y + (ray.step_y - 1) / 2]
				[(int)ray.horz_x] == '1')
				return (save_color(game, ray.horz_dist, ray.step_y + 2,
						ray.horz_w));
			else
				ray.horz_y += ray.step_y;
		}
	}
}

void	ft_ray_casting(t_game *game)
{
	int					x;
	float				dv;
	float				angle;
	static float		fov;

	fov = 60 * M_PI / 180;
	angle = game->map.view_angle - fov / 2;
	dv = fov / (WIDTH - 1);
	x = -1;
	while (++x < WIDTH)
	{
		draw_line(game, x, ft_ray(game, angle)
			* cos(game->map.view_angle - angle));
		angle += dv;
	}
}
