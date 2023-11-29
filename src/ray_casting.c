/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:03 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 12:25:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void    ray_init(t_game *game, t_ray *ray, float angle) // initialize ray
{
    ray->dir_x = cos(angle); // ray direction
    ray->dir_y = sin(angle); // ray direction
    ray->step_x = ft_sign(ray->dir_x); // step and side dist
    ray->step_y = ft_sign(ray->dir_y); // step and side dist
    ray->vert_x = (int)game->map.pos_x; // vertical wall hit
    if (ray->step_x > 0) // if ray direction is positive
        ray->vert_x += 1.0f; // add 1 to vertical wall hit
    ray->horz_y = (int)game->map.pos_y; // horizontal wall hit
    if (ray->step_y > 0) // if ray direction is positive
        ray->horz_y += 1.0f; // add 1 to horizontal wall hit
}

float ft_sign(float n)
{
    if (n > 0)
        return (1.0f);
    else if (n < 0)
        return (-1.0f);
    else
        return (0.0f);
}

static void    next_step_ray(t_game *game, t_ray *ray) // find next step of ray
{
    if (ray->step_x != 0) // if ray direction is not vertical
    {
        ray->vert_y = game->map.pos_y + ray->dir_y / ray->dir_x * (ray->vert_x - game->map.pos_x); // vertical wall hit = player position + ray direction * (vertical wall hit - player position)
        ray->vert_dist = sqrt(pow(game->map.pos_x - ray->vert_x, 2.0) + pow(game->map.pos_y - ray->vert_y, 2.0)); // distance from player to vertical wall hit = sqrt((player position - vertical wall hit)^2 + (player position - vertical wall hit)^2)
        ray->vert_w = ray->vert_y - (int)ray->vert_y; // vertical wall hit = vertical wall hit - (int)vertical wall hit
        if (ray->step_x > 0) // if ray direction is positive
            ray->vert_w = 1 - ray->vert_w; // vertical wall hit = 1 - vertical wall hit
    }
    else
        ray->vert_dist = INFINITY; // if ray direction is vertical, set distance to infinity
    if (ray->step_y != 0) // if ray direction is not horizontal
    {
        ray->horz_x = game->map.pos_x + ray->dir_x / ray->dir_y * (ray->horz_y - game->map.pos_y); // horizontal wall hit = player position + ray direction * (horizontal wall hit - player position)
        ray->horz_dist = sqrt(pow(game->map.pos_x - ray->horz_x, 2.0) + pow(game->map.pos_y - ray->horz_y, 2.0)); // distance from player to horizontal wall hit = sqrt((player position - horizontal wall hit)^2 + (player position - horizontal wall hit)^2)
        ray->horz_w = ray->horz_x - (int)ray->horz_x;   // horizontal wall hit = horizontal wall hit - (int)horizontal wall hit
        if (ray->step_y > 0) // if ray direction is positive
            ray->horz_w = 1 - ray->horz_w; // horizontal wall hit = 1 - horizontal wall hit
    }
    else
        ray->horz_dist = INFINITY; // if ray direction is horizontal, set distance to infinity
}

static float   save_color(t_game *game, float dist, int color_idx, float wall_hit) // save color index and wall hit
{
    game->txt_index = color_idx; // save color index
    game->txt_width = wall_hit; // save wall hit
    return (dist); // return distance to wall
}

float	ft_ray(t_game *game, float angle) // return distance to wall
{
    t_ray ray;

    ray_init(game, &ray, angle);
    while (1)
    {
        next_step_ray(game, &ray);
        if (ray.vert_dist < ray.horz_dist) // if distance to vertical wall hit is smaller than distance to horizontal wall hit
        {
            if (game->data.map[(int)ray.vert_y][(int)ray.vert_x + (ray.step_x - 1) / 2] == '1') // if vertical wall hit is wall
                return (save_color(game, ray.vert_dist, ray.step_x + 1, ray.vert_w)); // save color index and wall hit and return distance to wall
            else
                ray.vert_x += ray.step_x; // vertical wall hit = vertical wall hit + step
        }
        else
        {
            if (game->data.map[(int)ray.horz_y + (ray.step_y - 1) / 2][(int)ray.horz_x] == '1') // if horizontal wall hit is wall 
                return (save_color(game, ray.horz_dist, ray.step_y + 2, ray.horz_w)); // save color index and wall hit and return distance to wall
            else
                ray.horz_y += ray.step_y; // horizontal wall hit = horizontal wall hit + step
        }
        //printf("vert_w: %f, horz_w: %f\n", ray.vert_w, ray.horz_w);
    }
}

void    ft_ray_casting(t_game *game)
{
    int    x; // x position
    float  dv; // delta view angle
    float  angle; // view angle
    angle = game->map.view_angle - FOV / 2; // v = player's view angle - FOV / 2
    dv = FOV / (WIDTH - 1); // delta view angle = FOV / (WIDTH - 1)
    x = -1;
    while (++x < WIDTH) // for each x position
    {
        draw_line(game, x, ft_ray(game, angle) * cos(game->map.view_angle - angle)); // draw line = draw_line(game, x, distance to wall * cos(player's view angle - view angle))
        angle += dv; // view angle = view angle + delta view angle
    }
}