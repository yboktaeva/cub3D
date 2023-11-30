/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:52:13 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/30 12:48:07 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*We check if we have 2argc,
  the extension file finished by .cub and check if the file exist
  If one of these 3 are not ok ,the program stop*/

void	check_args(int argc, char **argv)
{
	char	*prompt;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File not exist\n");
	prompt = get_next_line(fd);
	if (prompt == NULL)
	{
		close(fd);
		free(prompt);
		ft_error("File is empty\n");
	}
	while (prompt && empty_line(prompt))
	{
		free(prompt);
		prompt = get_next_line(fd);
		if (prompt == NULL)
		{
			close(fd);
			free(prompt);
			ft_error("File is empty\n");
		}
	}
	free(prompt);
}

void	init_struct(t_game *game)
{
	int	i;

	game->mlx = NULL;
	game->win = NULL;
	game->file = NULL;
	game->txt_index = 0;
	game->txt_width = 0.0f;
	game->txt_height = 0.0f;
	init_img(&game->img);
	init_map(&game->map);
	game->txt = (t_txt *)malloc(sizeof(t_txt) * 4);
	if (game->txt == NULL)
		file_failure(game, "malloc failed for txt");
	game->path_nswe = NULL;
	init_txt(game->txt);
	i = -1;
	while (++i < 4)
		game->txt[i].img = NULL;
	init_data(&game->data);
	init_trgb(&game->ceiling);
	init_trgb(&game->floor);
}

int	main(int argc, char **argv)
{
	t_game	game;
	size_t	len;

	if (argc != 2)
		ft_error("Invalid number of arguments\n");
	len = ft_strlen(argv[1]);
	if (ft_strcmp(&argv[1][len - ft_strlen(".cub")], ".cub"))
		ft_error("Invalid file with format .cub\n");
	check_args(argc, argv);
	init_struct(&game);
	parse_cub(&game, argv[1]);
	start_game(&game);
	return (0);
}
