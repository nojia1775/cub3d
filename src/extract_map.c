/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:07:55 by noah              #+#    #+#             */
/*   Updated: 2024/10/07 14:22:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	true_size_map(t_global *global, int *begin, int *end, int *lines)
{
	t_cub	*cur;
	int		i;
	
	cur = get_pos_map(global);
	while (cur)
	{
		i = 0;
		while (cur->line[i])
		{
			if (cur->line[i] != ' ' && cur->line[i] != '\t')
			{
				if (i < *begin)
					*begin = i;
				break ;
			}
			i++;
		}
		i = ft_strlen(cur->line) - 1;
		while (i >= 0)
		{
			if (cur->line[i] != ' ' && cur->line[i--] != '\t')
			{
				if (i + 1 > *end)
					*end = i + 1;
				break ;
			}
			i++;
		}
		cur = cur->next;
		(*lines)++;
	}
}

static char	**supp_spaces(t_global *global)
{
	t_cub	*cur;
	int		begin;
	int		end;
	int		lines;
	int		i;
	char	**map;

	lines = 0;
	begin = 1000000;
	end = 0;
	cur = get_pos_map(global);
	true_size_map(global, &begin, &end, &lines);
	map = (char **)malloc(sizeof(char) * (lines + 1));
	if (!map)
		return (NULL);
	map[lines] = NULL;
	i = 0;
	while (i < lines)
	{
		map[i] = ft_strndup(cur->line + begin, (size_t)(end - begin + 1));
		if (!map[i])
			return (NULL);
		i++;
		cur = cur->next;
	}
	return (map);
}

static int	size_map(t_global *global, int *line, int *column)
{
	t_cub	*cur;

	global->map = supp_spaces(global);
	if (!global->map)
		return (0);
	cur = get_pos_map(global);
	while (cur)
	{
		(*line)++;
		if (ft_strlen(cur->line) > (size_t)(*column))
			*column = ft_strlen(cur->line);
		cur = cur->next;
	}
	return (1);
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
				&& cur->line[i] != 'W' && cur->line[i] != 'E'
				&& cur->line[i] != ' ')
				return (0);
			if (cur->line[i] == 'N' || cur->line[i] == 'S'
				|| cur->line[i] == 'E' || cur->line[i] == 'W')
				if (direction++ != 0)
					return (0);
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
	if (!size_map(global, &line, &column))
		return (0);
	return (1);
}
