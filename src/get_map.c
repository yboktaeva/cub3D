/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:35 by cqin              #+#    #+#             */
/*   Updated: 2023/11/28 15:23:38 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_line(char **file, int i)
{
	int	line;
	int	j;

	line = 1;
	while (i-- > 0)
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\n')
			j++;
		if (ft_isdigit(file[i][j]) == 1)
			line++;
		else if (file[i][j] == '\0')
			break ;
	}
	return (line);
}

ssize_t	length_line(char *line_map)
{
	int		i;
	ssize_t	length;

	i = -1;
	length = 0;
	while (line_map[++i])
	{
		if (line_map[i] == '\t')
		{
			length += 4;
		}
		else
			length++;
	}
	return (length);
}

void	copy_into(t_data *data, char *map_line, int x, t_map *map)
{
	int i;
	int j;
	(void)map;
	i = -1;
	j = 0;
	while (map_line[++i])
	{
		if (map_line[i] == '\t')
		{
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
			data->map[x][j++] = ' ';
		}
		else
		{
			data->map[x][j++] = map_line[i];
			// if (map_line[i] == 'N' || map_line[i] == 'S' || map_line[i] == 'W' || map_line[i] == 'E')
			// {
			// 	map->pos_x = x;
			// 	map->pos_y = j;
			// }
		}
	}
	data->map[x][j] = '\0';
}

void	map_into_data(int line, t_game *game, char **map)
{
	int		i;
	size_t	length_max;

	i = 0;
	length_max = 0;
	while (i < line)
	{
		game->data.map[i] = malloc(sizeof(char) * (length_line(map[i]) + 1));
		if (!game->data.map[i])
			file_failure(game, "malloc failure\n");
		copy_into(&game->data, map[i], i, &game->map);
		if (ft_strlen(game->data.map[i]) > length_max)
			length_max = ft_strlen(game->data.map[i]);
		i++;
	}
	game->data.row_max = length_max - 1;
	game->data.map[i] = NULL;
}

void	get_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file[i])
		i++;
	i--;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j] == ' ' || game->file[i][j] == '\t'
			|| game->file[i][j] == '\n')
			j++;
		if (ft_isdigit(game->file[i][j]))
			break ;
		else if (game->file[i][j] != '\0')
			file_failure(game, "map not at the end\n");
		i--;
	}
	game->data.map_line = map_line(game->file, i);
	game->data.map = malloc(sizeof(char *) * (game->data.map_line + 1));
	if (!game->data.map)
		file_failure(game, "malloc failure\n");
	map_into_data(game->data.map_line, game, &game->file[i - game->data.map_line
		+ 1]);
}
