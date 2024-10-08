/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:37 by nadjemia          #+#    #+#             */
/*   Updated: 2024/10/08 16:47:34 by nadjemia         ###   ########.fr       */
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

int	parsing_map(t_global *global)
{
	if (!null_line(global->map))
		return (0);
	return (1);
}