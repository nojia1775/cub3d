/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degat_des_eaux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:56:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/09 11:32:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	isitem(char *c)
{
	if (*c == 'N' || *c == 'S' || *c == 'W' || *c == 'E')
		(*c) += 32;
}

static void	row(char **map, int i, int j, int *count)
{
	int	tmp;

	tmp = i;
	*count = 0;
	while (i >= 0 && j >= 0 && map[i] && map[i][j] && map[i][j] != '1')
	{
		isitem(&map[i][j]);
		if (map[i][j] == '0')
		{
			(*count)++;
			map[i][j] = '.';
		}
		i++;
	}
	i = tmp;
	while (i >= 0 && j >= 0 && map[i] && map[i][j] && map[i][j] != '1')
	{
		isitem(&map[i][j]);
		if (map[i][j] == '0')
		{
			(*count)++;
			map[i][j] = '.';
		}
		i--;
	}
}

static void	line(char **map, int i, int j, int *count)
{
	int	tmp;

	tmp = j;
	while (i >= 0 && j >= 0 && map[i] && map[i][j] && map[i][j] != '1')
	{
		isitem(&map[i][j]);
		if (map[i][j] == '0')
		{
			(*count)++;
			map[i][j] = '.';
		}
		j++;
	}
	j = tmp;
	while (i >= 0 && j >= 0 && map[i] && map[i][j] && map[i][j] != '1')
	{
		isitem(&map[i][j]);
		if (map[i][j] == '0')
		{
			(*count)++;
			map[i][j] = '.';
		}
		j--;
	}
}

static void	setmap(char **map, void (*f)(char **, int, int, int *), int *count)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.' || map[i][j] == 'n'
				|| map[i][j] == 's' || map[i][j] == 'w'
				|| map[i][j] == 'e')
				f(map, i, j, count);
			j++;
		}
		i++;
	}
}

void	degat_des_eaux(char **map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				line(map, i, j, &count);
				while (count)
				{
					setmap(map, row, &count);
					setmap(map, line, &count);
				}
			}
			j++;	
		}
		i++;
	}
}
