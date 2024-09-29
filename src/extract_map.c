/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:07:55 by noah              #+#    #+#             */
/*   Updated: 2024/09/29 12:48:35 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	size_map(t_global *global, int *line, int *column)
{
	t_cub	*cur;

	cur = get_pos_map(global);
	while (cur)
	{
		(*line)++;
		if (ft_strlen(cur->line) > (size_t)(*column))
			*column = ft_strlen(cur->line);
		cur = cur->next;
	}
}

static int	valid_char(t_global *global)
{
	t_cub	*cur;
	int		direction;
	int		i;

	direction = 0;
	cur = get_pos_map(global);
	while (cur)
	{
		i = -1;
		while (cur->line[++i])
		{
			if (cur->line[i] != '0' && cur->line[i] != '1'
				&& cur->line[i] != 'N' && cur->line[i] != 'S'
				&& cur->line[i] != 'W' && cur->line[i] != 'E')
				return (0);
			if (cur->line[i] == 'N' || cur->line[i] == 'S'
				|| cur->line[i] == 'E' || cur->line[i] == 'W')
			{
				if (direction++ != 0)
					return (0);
			}
		}
		cur = cur->next;
	}
	return (direction);
}

int	extract_map(t_global *global)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	if (!valid_char(global))
		return (0);
	size_map(global, &line, &column);
	printf("line = %d column = %d\n", line, column);
	return (1);
}