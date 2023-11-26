/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:50:23 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/26 14:20:16 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_fileline(char *file, t_game *game)
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		file_failure(game, "open file failure\n");
	if ((line = get_next_line(fd)) == NULL)
		file_failure(game, "file empty\n");
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

	if ((line = get_next_line(fd)) == NULL)
		file_failure(game, "file empty\n");
	while (line)
	{
		j = -1;
		if ((game->file[i] = malloc(sizeof(char) * (ft_strlen(line) + 1))) == NULL)
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
	if ((game->file = malloc(sizeof(char *) * (file_len + 1))) == NULL)
	{
		close(fd);
		file_failure(game, "malloc failure\n");
	}
	if ((fd = open (path, O_RDONLY)) < 0)
	{
		close(fd);
		file_failure(game, "open failure\n");
	}
	get_line(game, 0, 0, fd);
}

