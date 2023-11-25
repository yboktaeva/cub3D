/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:44:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/25 15:19:41 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_data(&game->data);
	if (game->file)
        free_line(game->file);
}

void	file_failure(t_game *game, char *msg)
{
	if (game->file)
        free_line(game->file);
	if (game->mlx != NULL)
		destroy_game(game);
	free_data(&game->data);
	ft_error(msg);
}

void	free_line(char **line)
{
	int i;

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
	if (data->north)
		free(data->north);
	if (data->south)
		free(data->south);
	if (data->west)
		free(data->west);
	if (data->east)
		free(data->east);
	if (data->map)
		free_line(data->map);
}