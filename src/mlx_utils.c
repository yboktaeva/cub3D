/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:27 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/30 14:26:17 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_fcvalid(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == ',')
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i]) || str[i] == ' ' || ft_isdigit(str[i])
			|| str[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isprint(str[i]) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	init_path_nswe(t_game *game)
{
	game->path_nswe = (char **)malloc(sizeof(char *) * (4 + 1));
	if (!game->path_nswe)
		file_failure(game, "malloc failed for path_nswe");
	game->path_nswe[0] = NULL;
	game->path_nswe[1] = NULL;
	game->path_nswe[2] = NULL;
	game->path_nswe[3] = NULL;
	return (-1);
}

void	if_exist(t_game *game, int f)
{
	if (f == 0 && game->ceiling.b != -1
		&& game->ceiling.g != -1 && game->ceiling.r != -1)
		file_failure(game, "ceiling color is duplicated\n");
	if (f == 1 && game->floor.b != -1
		&& game->floor.g != -1 && game->floor.r != -1)
		file_failure(game, "floor color is duplicated\n");
}
