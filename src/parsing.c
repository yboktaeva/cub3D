/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:29:34 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/30 11:05:52 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	direction(char **map, int i, int j, t_game *game)
{
	int	line_end;
	int	k;

	k = 0;
	line_end = i + j;
	while (i < line_end)
	{
		if (map[i + 1] == NULL || (map[i + 1] && empty_line(map[i + 1]) == 1))
			file_failure(game, "An empty line between or double elements\n");
		k = 0;
		if (j == 3)
		{
			while (!ft_isprint(map[i + 1][k]) || map[i + 1][k] == ' ')
				k++;
			if (ft_strlen(map[i + 1]) > 4 && (((map[i + 1][k] == 'N' || (map[i
								+ 1][k] == 'S')) && map[i + 1][k + 1] == 'O')
					|| (map[i + 1][k] == 'E' && map[i + 1][k + 1] == 'A')
					|| (map[i + 1][k] == 'W' && map[i + 1][k + 1] == 'E')))
				;
			else
				file_failure(game, "invalid texture file\n");
		}
		i++;
	}
}

void	check_file2(char **map, t_game *game, int *i, int j)
{
	while (map[*i][j])
	{
		while (map[*i][j] && (!ft_isprint(map[*i][j]) || map[*i][j] == ' '))
			j++;
		if (ft_strlen(map[*i]) > 4 && (((map[*i][j] == 'N' || map[*i][j] == 'S')
			&& map[*i][j + 1] == 'O') || (map[*i][j] == 'E' && map[*i][j
			+ 1] == 'A') || (map[*i][j] == 'W' && map[*i][j + 1] == 'E')))
		{
			direction(game->file, *i, 3, game);
			(*i) += 3;
			break ;
		}
		else if (ft_strlen(map[*i]) > 3 && (map[*i][j] == 'F' || map[*i][j]
			== 'C'))
		{
			direction(game->file, *i, 1, game);
			(*i) += 1;
			break ;
		}
		else if (!empty_line(map[*i]) && !ft_isdigit(map[*i][j]))
			file_failure(game, "file not conform\n");
		else
			break ;
	}
}

void	check_file(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		check_file2(map, game, &i, j);
		i++;
	}
}

void	parse_cub(t_game *game, char *map_name)
{
	get_file(map_name, game);
	if (is_texture(game->file))
		get_texture(game, 0);
	if (is_color(game->file))
	{
		get_color(game);
		game->data.floor_color = rgb_to_hex(game->floor);
		game->data.ceiling_color = rgb_to_hex(game->ceiling);
	}
	else
		file_failure(game, "no color found\n");
	check_file(game->file, game);
	only_onemap(game->file, game);
	get_map(game);
	parse_map(game);
	if (game->data.ceiling_color == 0 || game->data.floor_color == 0
		|| game->path_nswe == NULL || game->txt == NULL
		|| game->data.map == NULL)
		file_failure(game, "file cub not conform\n");
}
