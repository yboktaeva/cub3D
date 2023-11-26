/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/26 15:16:09 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    get_texture(t_game *game)
{
    int i;
    int j;
    char **strs;
    
    if ((game->path_nswe = (char **)malloc(sizeof(char *) * 4)) == NULL)
        file_failure(game, "malloc failed for path_nswe");
    i = 0;
    while (game->file[i])
    {
        j = 0;
        strs = ft_split(game->file[i], ' ');
        while (strs[j])
        {
            if (strs[j][0] == 'N' && strs[j][1] == 'O')
                game->path_nswe[game->txt_index] = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'S' && strs[j][1] == 'O')
                game->path_nswe[game->txt_index] = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'W' && strs[j][1] == 'E')
                game->path_nswe[game->txt_index] = ft_strdup(strs[j + 1]);
            else if (strs[j][0] == 'E' && strs[j][1] == 'A')
                game->path_nswe[game->txt_index]= ft_strdup(strs[j + 1]);
            j++;
        }
        game->txt_index++;
        free_line(strs);
        i++;
    }
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

void    init_texture_files(t_game *game)
{
    int i;

    i = -1;
    while (++i < 4)
    {
        game->txt[i].img = mlx_xpm_file_to_image(game->mlx, game->path_nswe[i], &game->txt[i].width, &game->txt[i].height);
        if (game->txt[i].img == NULL)
            file_failure(game, "texture file failure\n");
        game->txt[i].addr = mlx_get_data_addr(game->txt[i].img, &game->txt[i].bpp, &game->txt[i].line_len, &game->txt[i].endian);
    }
}