/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 18:08:33 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    get_texture(t_game *game)
{
    int i;
    int j;
    char **strs;
    
    i = 0;
    while (game->file[i])
    {
        j = 0;
        strs = ft_split(game->file[i], ' ');
        while (strs[j])
        {
            if (strs[j][0] == 'N' && strs[j][1] == 'O')
                game->txt[game->txt_index].path_nswe = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'S' && strs[j][1] == 'O')
                game->txt[game->txt_index].path_nswe = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'W' && strs[j][1] == 'E')
                game->txt[game->txt_index].path_nswe = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'E' && strs[j][1] == 'A')
                 game->txt[game->txt_index].path_nswe= ft_strdup(strs[j + 1]);
            game->txt_index++;
            j++;
        }
        free_line(strs);
        i++;
    }
    printf("game->txt[NO].path_nswe: %s\n", game->txt[0].path_nswe);
    printf("game->txt[SO].path_nswe: %s\n", game->txt[1].path_nswe);
    printf("game->txt[WE].path_nswe: %s\n", game->txt[2].path_nswe);
    printf("game->txt[EA].path_nswe: %s\n", game->txt[3].path_nswe);
}

void    get_color(t_game *game)
{
    int i;
    int j;
    char **strs;

    i = 0;
    while (game->file[i])
    {
        j = 0;
        strs = ft_split(game->file[i], ' ');
        while (strs[j])
        {
            if (is_color(strs))
            {
                if (strs[j][0] == 'F')
                {
                    if (check_floor(game, strs[j + 1]))
                        free_line(strs);
                }
                else if (strs[j][0] == 'C')
                {
                    if (check_ceiling(game, strs[j + 1]))
                        free_line(strs);
                }
            }
            j++;
        }
        free_line(strs);
        i++;
    }
}