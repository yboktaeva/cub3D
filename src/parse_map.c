/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:35 by cqin              #+#    #+#             */
/*   Updated: 2023/11/28 18:33:16 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_elements(char **map)
{
	int		i;
	int		j;
	ssize_t	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != '\t' && map[i][j] != '\n' && map[i][j] != 'N'
				&& map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'E')
				return (1);
			else if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != '\n')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1 || player == 0)
		return (1);
	return (0);
}

int	dfs(char **map, int i, int j, t_data *data)
{
	if (i == -1 || i == data->map_line - 1 || j == 0 || j == data->row_max - 1)
		return (0);
	if (map[i][j] == '0')
	{
		if (((i + 1 <= data->map_line) && (j >= (int)ft_strlen(map[i + 1]) - 1))
			|| (i - 1 >= 0 && (j >= (int)ft_strlen(map[i - 1]) - 1)))
			return (-1);
	}
	if (map[i][j] == '1' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == '2')
		return (0);
	else if (map[i][j] == '0')
		map[i][j] = '2';
	else if (map[i][j] == ' ')
		return (-1);
	if (dfs(map, i - 1, j, data) == -1 || dfs(map, i, j + 1, data) == -1
		|| dfs(map, i + 1, j, data) == -1 || dfs(map, i, j - 1, data) == -1)
		return (-1);
	return (0);
}

int	map_isclosed(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || i == (data->map_line - 1) || j == 0
					|| j == (data->row_max - 1))
					return (1);
				if (dfs(map, i, j, data) == -1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_mapdir(t_map *map, char **maps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (maps[i])
	{
		if (ft_strchr(maps[i], 'N'))
		{
			map->dir_x = 0;
			map->dir_y = -1;
		}
		else if (ft_strchr(maps[i], 'E'))
		{
			map->dir_x = 1;
			map->dir_y = 0;
		}
		else if (ft_strchr(maps[i], 'S'))
		{
			map->dir_x = 0;
			map->dir_y = 1;
		}
		else if (ft_strchr(maps[i], 'W'))
		{
			map->dir_x = -1;
			map->dir_y = 0;
		}
		i++;
	}
}

void	parse_map(t_game *game)
{
	char	**map_duplicate;

	map_duplicate = game->data.map;
	if (check_elements(game->data.map) == 1)
		file_failure(game, "character not accepted or not only one player\n");
	if (map_isclosed(map_duplicate, &game->data) == 1)
		file_failure(game, "map not closed\n");
	init_mapdir(&game->map, game->data.map);
}