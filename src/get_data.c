/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/28 15:13:33 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    get_texture(t_game *game)
{
    int i;
    int j;
    char **strs;
    
    if ((game->path_nswe = (char **)malloc(sizeof(char *) * (4 + 1))) == NULL)
        file_failure(game, "malloc failed for path_nswe");
    i = 0;
    while (game->file[i])
    {
        j = 0;
        strs = ft_split(game->file[i], ' ');
        while (strs[j])
        {
            if (strs[j][0] == 'N' && strs[j][1] == 'O')
            {
                game->path_nswe[0] = ft_substr(strs[j + 1], 0, ft_strlen(strs[j + 1]) - 1);
                game->txt_index = 0;
            }
            else if (strs[j][0] == 'S' && strs[j][1] == 'O')
            {
                game->path_nswe[1] = ft_substr(strs[j + 1], 0, ft_strlen(strs[j + 1]) - 1);
                game->txt_index = 1;
            }
            else if (strs[j][0] == 'W' && strs[j][1] == 'E')
            {
                game->path_nswe[2] = ft_substr(strs[j + 1], 0, ft_strlen(strs[j + 1]) - 1);
                game->txt_index = 2;
            }
            else if (strs[j][0] == 'E' && strs[j][1] == 'A')
            {
                game->path_nswe[3]= ft_substr(strs[j + 1], 0, ft_strlen(strs[j + 1]) - 1);
                game->txt_index = 3;
            }
            j++;
        }
        free_line(strs);
        i++;
    }
    game->path_nswe[4] = NULL;
}

void    get_color(t_game *game)
{
    int i;

    i = 0;
    while (game->file[i])
    {
        if (game->file[i][0] == 'F')
            check_floor(game, game->file[i]);
        else if (game->file[i][0] == 'C')
            check_ceiling(game, game->file[i]);
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
            file_failure(game, "wall texture file failure\n");
        game->txt[i].addr = mlx_get_data_addr(game->txt[i].img, &game->txt[i].bpp, &game->txt[i].line_len, &game->txt[i].endian);
    }
}