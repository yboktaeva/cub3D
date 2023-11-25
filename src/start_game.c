/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:31:41 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 17:09:23 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        ft_error("mlx_init() failed\n");
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
    //check_position(game); // check player's position
    draw_game(game); // draw game
    mlx_hook(game->win, DestroyNotify, 0, &close_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, &key_press, game);
    mlx_loop(game->mlx);
}
