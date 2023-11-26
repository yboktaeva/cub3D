/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:21:35 by cqin              #+#    #+#             */
/*   Updated: 2023/11/26 13:25:29 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_line(char **start_map)
{
	ssize_t line;
	int j;

	line = 0;
	while (start_map[line])
	{
		j = 0;
		while (start_map[line][j] == ' ' || start_map[line][j] == '\t')
			j++;
		if (start_map[line][j] == '\0' || start_map[line][j] == '\n')
			return (line);
		line++;
	}
	return (line);
}

void	map_into_data(ssize_t line, t_data *data, char **map)
{
	ssize_t i;

	i = 0;
	while (i < line)
	{
		data->map[i] = ft_strdup(map[i]);
		i++;
	}
	data->map[i] = NULL;
}

void	get_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j] == ' ' || game->file[i][j] == '\t')
			j++;
		if (ft_isdigit(game->file[i][j]))
			break;
		i++;
	}
	if (i < 7)
		file_failure(game, "map not a the end\n");
	game->data.map = malloc(sizeof(char *) * (map_line(&game->file[i]) + 1));
	if (!game->data.map)
		file_failure(game, "malloc failure\n");
	map_into_data(map_line(&game->file[i]), &game->data, &game->file[i]);
}
