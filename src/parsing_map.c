/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:37 by nadjemia          #+#    #+#             */
/*   Updated: 2024/10/09 15:00:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	rm_lines_under_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (empty_line(map[i]))
		{
			free(map[i]);
			map[i] = NULL;
		}
		else
			break ;
		i--;
	}
}

static int	map_closed(char **map)
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

int	parsing_map(t_global *global)
{
	rm_lines_under_map(global->map);
	if (!map_closed(global->map))
		return (0);
	return (1);
}
