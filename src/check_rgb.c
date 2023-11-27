/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:14:00 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/27 18:27:38 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_rgb(char *str)
{
    int i;

    i = 0;
    if (ft_atoi(&str[i]) < 0 || ft_atoi(&str[i]) > 255)
        return (0);
    return (1);
}

void    *check_ceiling(t_game *game, char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]) || str[i] == ',' || str[i] == 'C')
        i++;
     if (!ft_isdigit(str[i])|| !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->ceiling.r = ft_atoi(&str[i]);
    while (ft_isdigit(str[i]))
        i++;
    while (ft_isspace(str[i]) || str[i] == ',')
        i++;
    if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->ceiling.g = ft_atoi(&str[i]);
    while (ft_isdigit(str[i]))
        i++;
    while (ft_isspace(str[i]) || str[i] == ',')
        i++;
    if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->ceiling.b = ft_atoi(&str[i]);
    return (NULL);
}

void    *check_floor(t_game *game, char *str)
{
    int i;

    i = 0;
    while (ft_isspace(str[i]) || str[i] == ',' || str[i] == 'F')
        i++;
    if (!ft_isdigit(str[i])|| !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->floor.r = ft_atoi(&str[i]);
    while (ft_isdigit(str[i]))
        i++;
    while (ft_isspace(str[i]) || str[i] == ',')
        i++;
    if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->floor.g = ft_atoi(&str[i]);
    while (ft_isdigit(str[i]))
        i++;
    while (ft_isspace(str[i]) || str[i] == ',')
        i++;
    if (!ft_isdigit(str[i]) || !check_rgb(&str[i]))
        file_failure(game, "is not a digit or RGB error\n");
    game->floor.b = ft_atoi(&str[i]);
    return (NULL);
}

