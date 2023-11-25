/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:23 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/24 18:35:19 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_fileline(char *file, t_game *game)
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		file_failure(game, "open file failure\n");
	line = get_next_line(fd);
	if (line == NULL)
		file_failure(game, "empty file\n");
	while (line != NULL)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb_line);
}

void	get_line(t_game *game, int i, int j, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		file_failure(game, "file empty\n");
	while (line)
	{
		j = -1;
		game->file[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!game->file[i])
		{
			close(fd);
			free(line);
			file_failure(game, "malloc failure\n");
		}
		while (line[++j] != '\0')
			game->file[i][j] = line[j];
		game->file[i][j] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->file[i] = NULL;
	close(fd);
}


void	get_file(char *path, t_game *game)
{
	int		file_len;
	int		fd;

	fd = 0;
	file_len = get_fileline(path, game);
	game->file = malloc(sizeof(char *) * (file_len + 1));
	if (!game->file)
	{
		close(fd);
		file_failure(game, "malloc failure\n");
	}
	fd = open (path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		file_failure(game, "open failure\n");
	}
	get_line(game, 0, 0, fd);
}

