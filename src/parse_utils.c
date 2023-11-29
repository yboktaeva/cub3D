/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:36:21 by yuboktae          #+#    #+#             */
/*   Updated: 2023/11/29 17:42:17 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_texture(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == 'N' && strs[i][1] == 'O')
			return (1);
		else if (strs[i][0] == 'S' && strs[i][1] == 'O')
			return (1);
		else if (strs[i][0] == 'W' && strs[i][1] == 'E')
			return (1);
		else if (strs[i][0] == 'E' && strs[i][1] == 'A')
			return (1);
		i++;
	}
	return (0);
}

int	is_color(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i][0] == 'F' || strs[i][0] == 'C')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

float ft_sign(float n)
{
    if (n > 0)
        return (1.0f);
    else if (n < 0)
        return (-1.0f);
    else
        return (0.0f);
}

int        str_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]) || ft_isdigit(str[i]) || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'A')
            i++;
        else
            return (0);
    }
    return (1);
}