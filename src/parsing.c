/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:34 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/26 14:34:23 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_cub(t_game *game, char *map_name)
{
	get_file(map_name, game);
	get_map(game);
    if (is_texture(game->file))
        get_texture(game);
    if (is_color(game->file))
    {
        get_color(game);
        game->data.floor_color = rgb_to_hex(game->floor);
        game->data.ceiling_color = rgb_to_hex(game->ceiling);
    }
    else
        file_failure(game, "No color found\n");
}

// void    xpm_file(t_game *game)
// {
//     if (ft_strncmp(game->data.north + ft_strlen(game->data.north) - 5, ".xpm", 4))
//         file_failure(game, "North: not .xpm file\n");
//     if (ft_strncmp(game->data.south + ft_strlen(game->data.south) - 5, ".xpm", 4))
//         file_failure(game, "South: not .xpm file\n");
//     if (ft_strncmp(game->data.west + ft_strlen(game->data.west) - 5, ".xpm", 4))
//         file_failure(game, "West: not .xpm file\n");
//     if (ft_strncmp(game->data.east + ft_strlen(game->data.east) - 5, ".xpm", 4))
//         file_failure(game, "East: not .xpm file\n");
// }
