/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:31:41 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 13:31:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        ft_error("mlx_init() failed\n");
    init_texture_files(game);
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
    if (!game->win)
    {
        free(game->mlx);
        ft_error("mlx_new_window() failed\n");
    }
}

void    start_game(t_game *game)
{
    init_window(game);
    find_position(game);
    draw_game(game);
    mlx_hook(game->win, DestroyNotify, 0, &close_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, &key_press, game);
    mlx_loop(game->mlx);
}

static void find_angle_view(char c, t_game *game)
{
    if (c == 'N')
        game->map.view_angle = 1.5f * M_PI;
    else if (c == 'S')
        game->map.view_angle = 0.5f * M_PI;
    else if (c == 'W')
        game->map.view_angle = M_PI;
    else if (c == 'E')
        game->map.view_angle = 0.0f;
}

void find_position(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->data.map[++i])
    {
        j = -1;
        while (game->data.map[i][++j])
        {
            if (ft_strchr("NSEW", game->data.map[i][j]))
            {
                game->map.pos_x = (float)j + 0.2f;
                game->map.pos_y = (float)i + 0.2f;
                find_angle_view(game->data.map[i][j], game);
                return ;
            }
        }
    }
}
