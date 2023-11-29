/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:27 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 19:50:40 by yuboktae         ###   ########.fr       */
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
	game->path_nswe[0] = NULL;
	game->path_nswe[1] = NULL;
	game->path_nswe[2] = NULL;
	game->path_nswe[3] = NULL;
	return (-1);
}
