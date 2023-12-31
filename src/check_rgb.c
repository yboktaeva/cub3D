/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:14:00 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/30 12:47:05 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_rgb(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(&str[i]) < 0 || ft_atoi(&str[i]) > 255)
		return (0);
	return (1);
}

int	skip_spacecomma(int i, char *str, t_game *game)
{
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != ',')
		file_failure(game, "is not a digit or RGB error\n");
	while (ft_isspace(str[++i]))
		;
	return (i);
}

int	color_loop(t_game *game, char *str, char c, int floor)
{
	int	i;

	i = 0;
	if_exist(game, floor);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == c)
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

void	*check_ceiling(t_game *game, char *str)
{
	int	i;

	i = color_loop(game, str, 'C', 0);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->ceiling.r = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, game);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->ceiling.g = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, game);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->ceiling.b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		file_failure(game, "is not a digit or RGB error\n");
	return (NULL);
}

void	*check_floor(t_game *game, char *str)
{
	int	i;

	i = color_loop(game, str, 'F', 1);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->floor.r = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, game);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->floor.g = ft_atoi(&str[i]);
	i = skip_spacecomma(i, str, game);
	if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
		file_failure(game, "is not a digit or RGB error\n");
	game->floor.b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		file_failure(game, "is not a digit or RGB error\n");
	return (NULL);
}
