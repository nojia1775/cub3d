/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:37 by nadjemia          #+#    #+#             */
/*   Updated: 2024/10/09 11:47:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	null_line(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (map[i])
	{
		flag = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (0);
		i++;
	}
	return (1);
}

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

int	parsing_map(t_global *global)
{
	rm_lines_under_map(global->map);
	if (!null_line(global->map))
		return (0);
	if (!map_closed(global->map))
		return (0);
	return (1);
}