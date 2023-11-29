/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 15:21:51 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_game(t_game *game)
{
	if (game->file)
		free_line(game->file);
	free_texture(game);
	free_data(&game->data);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	file_failure(t_game *game, char *msg)
{
	destroy_game(game);
	ft_error(msg);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
	line = NULL;
}

void	free_data(t_data *data)
{
	if (data->map)
		free_line(data->map);
}

void	free_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->path_nswe && game->path_nswe[i])
			free(game->path_nswe[i]);
		if (game->txt[i].img)
			mlx_destroy_image(game->mlx, game->txt[i].img);
		i++;
	}
	free(game->path_nswe);
	free(game->txt);
}
