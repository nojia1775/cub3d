/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:38:27 by codespace         #+#    #+#             */
/*   Updated: 2024/10/09 11:44:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	map_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				if (i == 0 || j == 0 || j == (int)ft_strlen(map[i]) - 1
					|| !map[i + 1])
					return (0);
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' '
					|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
