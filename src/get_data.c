/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 17:42:50 by yuboktae         ###   ########.fr       */
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
	int j;

	i = 0;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j] && (!ft_isprint(game->file[i][j]) || game->file[i][j] == ' '))
			j++;
		if (game->file[i][j] == 'F')
			check_floor(game, game->file[i]);
		else if (game->file[i][j] == 'C')
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
		if (game->path_nswe[i] == NULL)
			file_failure(game, "no texture file\n");
		game->txt[i].img = mlx_xpm_file_to_image(game->mlx, game->path_nswe[i], &game->txt[i].width, &game->txt[i].height);
		if (game->txt[i].img == NULL)
			file_failure(game, "wall texture file failure\n");
		game->txt[i].addr = mlx_get_data_addr(game->txt[i].img, &game->txt[i].bpp, &game->txt[i].line_len, &game->txt[i].endian);
	}
}

void    only_onemap(char **file, t_game *game)
{
    int        i;
    int        j;

    i = 0;
    while (file[i])
    {
        j = 0;
        while (file[i][j])
        {
            if (ft_isspace(file[i][j]))
                j++;
            else
                break;
        }
        if (ft_isdigit(file[i][j]))
            break;
        i++;
    }
    while (file[i] && (str_digit(file[i]) && !empty_line(file[i])))
        i++;
    if (file[i] != NULL)
        file_failure(game, "we need only one map\n");
}