/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:49:17 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/24 10:15:18 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*get_new_save(char *save, char *line)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\0' && save[i] == line[i])
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	new_save = (char *)malloc(sizeof(char)
			* ((int)ft_strlen(save) - (int)ft_strlen(line) + 1));
	if (!new_save)
		return (NULL);
	j = 0;
	while (save[i] != '\0')
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*save_to_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (0);
	while ((save[i] != '\n') && (save[i] != '\0'))
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = save[j];
	if (save[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*buffer_to_save(char *save, char *buffer)
{
	int		i;
	int		j;
	char	*dest;

	if (!save)
	{
		save = malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	if (!save || !buffer)
		return (NULL);
	dest = (char *)malloc(sizeof(char)
			* ((int)ft_strlen(save) + (int)ft_strlen(buffer) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (save[++i] != '\0')
		dest[i] = save[i];
	j = 0;
	while (buffer[j] != '\0')
		dest[i++] = buffer[j++];
	dest[i] = '\0';
	return (free(save), dest);
}

char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_bytes != 0 && ft_strchr(save, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save = buffer_to_save(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	save = read_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = save_to_line(save);
	save = get_new_save(save, line);
	return (line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("trip/files/42_with_nl", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		if (line == NULL)
// 			break ;
// 	}
// }
