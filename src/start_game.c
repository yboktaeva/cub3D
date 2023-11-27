/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:31:41 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/27 18:33:47 by yuboktae         ###   ########.fr       */
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
    printf("posX = %f\n", game->map.pos_x);
	printf("posY = %f\n", game->map.pos_y);
	printf("dirX = %f\n", game->map.dir_x);
	printf("dirY = %f\n", game->map.dir_y);
	printf("planeX = %f\n", game->map.plane_x);
	printf("planeY = %f\n", game->map.plane_y);
    //check_position(game); // check player's position
    draw_game(game); // draw game
    mlx_hook(game->win, DestroyNotify, 0, &close_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, &key_press, game);
    mlx_loop(game->mlx);
}

void check_position(t_game *game)
{
    int i;
    int j;

    i = -1;
    while (game->data.map[++i])
    {
        j = 0;
        while (game->data.map[i][++j])
        {
            if (ft_strchr("NSEW", game->data.map[i][j]))
            {
                game->map.pos_x = (float)j + 0.5f;
                game->map.pos_y = (float)i + 0.5f;
                find_direction(game->data.map[i][j], game);
                return ;
            }
        }
    }
}