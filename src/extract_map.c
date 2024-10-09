/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:07:55 by noah              #+#    #+#             */
/*   Updated: 2024/10/09 15:14:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	iter(t_cub *cur, int *begin)
{
	int	i;

	i = 0;
	while (cur->line[i])
	{
		if (cur->line[i] != ' ' && cur->line[i] != '\t' && cur->line[i] != '\n')
		{
			if (i < *begin)
				*begin = i;
			break ;
		}
		i++;
	}
}

static void	true_size_map(t_global *global, int *begin, int *end, int *lines)
{
	t_cub	*cur;
	int		i;
	
	cur = get_pos_map(global);
	while (cur)
	{
		iter(cur, begin);
		i = ft_strlen(cur->line) - 1;
		while (i >= 0)
		{
			if (cur->line[i] != ' ' && cur->line[i] != '\t'
			&& cur->line[i] != '\n')
			{
				if (i + 1 > *end)
					*end = i + 1;
				break ;
			}
			i--;
		}
		cur = cur->next;
		(*lines)++;
	}
}


static char	**supp_spaces(t_global *global)
{
	t_vars	vars;

	vars.lines = 0;
	vars.begin = 1000000;
	vars.end = 0;
	vars.cur = get_pos_map(global);
	true_size_map(global, &vars.begin, &vars.end, &vars.lines);
	vars.map = (char **)malloc(sizeof(char *) * (vars.lines + 1));
	if (!vars.map)
		return (NULL);
	vars.map[vars.lines] = NULL;
	vars.i = 0;
	while (vars.i < vars.lines && vars.cur)
	{
		if (ft_strlen(vars.cur->line) > (size_t)vars.begin)
			vars.map[vars.i] = ft_strndup(vars.cur->line + vars.begin, (size_t)(vars.end - vars.begin));
		else
			vars.map[vars.i] = ft_strndup("", (size_t)(vars.end - vars.begin));
		if (!vars.map[vars.i])
			return (NULL);
		vars.i++;
		vars.cur = vars.cur->next;
	}
	return (vars.map);
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
				&& cur->line[i] != ' ' && cur->line[i] != '\n')
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
	global->map = supp_spaces(global);
	if (!valid_char(global))
		return (0);
	if (!global->map)
		return (0);
	return (1);
}
