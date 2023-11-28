/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:03 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/28 15:27:36 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    ray_init(t_game *game, t_ray *ray, float angle)
{
    ray->dir_x = cos(angle) * 0.1;
    ray->dir_y = sin(angle) * 0.1;
    ray->step_x = ft_sign(ray->dir_x);
    ray->step_y = ft_sign(ray->dir_y);
    ray->vert_x = (int)game->map.pos_x;
    if (ray->step_x > 0)
        ray->vert_x += 1.0f;
    ray->horz_y = (int)game->map.pos_y;
    if (ray->step_y > 0)
        ray->horz_y += 1.0f;
}

float ft_sign(float n) {
    if (n > 0) {
        return 1.0f;
    } else if (n < 0) {
        return -1.0f;
    } else {
        return 0.0f;
    }
}

static void    next_step_ray(t_game *game, t_ray *ray)
{
    if (ray->step_x != 0)
    {
        ray->vert_y = game->map.pos_y + ray->dir_y / ray->dir_x * (ray->vert_x - game->map.pos_x);
        ray->vert_dist = sqrt(pow(game->map.pos_x - ray->vert_x, 2.0) + pow(game->map.pos_y - ray->vert_y, 2.0));
        ray->vert_w = ray->vert_y - (int)ray->vert_y;
        if (ray->step_x > 0)
            ray->vert_w = 1.0f - ray->vert_w;
    }
    else    ray->vert_dist = INFINITY;
    if (ray->step_y != 0)
    {
        ray->horz_x = game->map.pos_x + ray->dir_x / ray->dir_y * (ray->horz_y - game->map.pos_y);
        ray->horz_dist = sqrt(pow(game->map.pos_x - ray->horz_x, 2.0) + pow(game->map.pos_y - ray->horz_y, 2.0));
        ray->horz_w = ray->horz_x - (int)ray->horz_x;
        if (ray->step_y > 0)
            ray->horz_w = 1.0f - ray->horz_w;
    }
    else    ray->horz_dist = INFINITY;
}

static float   save_color(t_game *game, float dist, int color_idx, float w)
{
    game->txt_index = color_idx;
    game->txt_width = w;
    return (dist);
}

float	ft_ray(t_game *game, float angle) // return distance to wall
{
    t_ray ray;

    ray_init(game, &ray, angle);
    while (1)
    {
        next_step_ray(game, &ray);
        if (ray.vert_dist < ray.horz_dist)
        {
            if (game->data.map[(int)ray.vert_y][(int)ray.vert_x + (ray.step_x - 1) / 2] == '1')
                return (save_color(game, ray.vert_dist, ray.step_x + 1, ray.vert_w));
            else
                ray.vert_x += ray.step_x;
        }
        else
        {
            if (game->data.map[(int)ray.horz_y + (ray.step_y - 1) / 2][(int)ray.horz_x] == '1')
                return (save_color(game, ray.horz_dist, ray.step_y + 2, ray.horz_w));
            else
                ray.horz_y += ray.step_y;
        }
    }
}

void    ft_ray_casting(t_game *game)
{
    int    x;
    float  dv;
    float  v;

    v = game->map.view_angle - (FOV / 2);
    dv = FOV / (WIDTH - 1);
    x = -1;
    while (++x < WIDTH)
    {
        draw_line(game, x, ft_ray(game, v) * cos(v - game->map.view_angle)); //against fish eye effect
        v += dv;
    }
}