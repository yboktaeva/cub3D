/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:36:38 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/21 15:27:20 by yuboktae         ###   ########.fr       */
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
	// key_move(keysym, game);
	// key_color(keysym, game);
	return (0);
}