/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:52:13 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/28 18:41:30 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*We check if we have 2argc,
the extension file finished by .cub and check if the file exist
If one of these 3 are not ok ,the program stop*/
void	check_args(int argc, char **argv)
{
	size_t	len;
	int	fd;

	if (argc != 2)
		ft_error("Invalid number of arguments\n");
	len = ft_strlen(argv[1]);
	if (ft_strcmp(&argv[1][len - ft_strlen(".cub")], ".cub"))
		ft_error("Invalid file with format .cub\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File not exist\n");
}

int main(int argc, char **argv)
{
    t_game game;

    check_args(argc, argv);
    init_struct(&game);
    parse_cub(&game, argv[1]);
	start_game(&game);
    return (0);
}
