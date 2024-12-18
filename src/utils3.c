/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:38:27 by codespace         #+#    #+#             */
/*   Updated: 2024/11/01 12:48:24 by nadjemia         ###   ########.fr       */
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

void	get_player_coor(double *x, double *y, t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (global->map[i])
	{
		j = 0;
		while (global->map[i][j])
		{
			if (global->map[i][j] == 'N' || global->map[i][j] == 'S'
				|| global->map[i][j] == 'W'
				|| global->map[i][j] == 'E')
			{
				*x = j;
				*y = i;
			}
			j++;	
		}
		i++;
	}
}
