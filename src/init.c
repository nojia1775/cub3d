/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:25:13 by noah              #+#    #+#             */
/*   Updated: 2024/11/05 12:12:05 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	elem_or_map(char *str, t_global *global, int *i)
{
	char	*tmp;

	tmp = NULL;
	if (*i < 6)
	{
		tmp = ft_strtrim(str, " \n\t");
		if (tmp[0] && ++(*i))
			add_list(&global->file, tmp);
	}
	else
	{
		if (++(*i))
			add_list(&global->file, str);
	}
	free_and_null((void **)&tmp);
	return (1);
}

static int	extract_file(t_global *global, char *map)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	str = "";
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (!elem_or_map(str, global, &i))
			return (0);
		free(str);
	}
	return (1);
}

int	init_global(t_global *global, char *map)
{
	global->south = NULL;
	global->north = NULL;
	global->east = NULL;
	global->west = NULL;
	global->map = NULL;
	global->file = NULL;
	global->floor = NULL;
	global->ceiling = NULL;
	global->mlx = NULL;
	global->win = NULL;
	global->img = NULL;
	global->player = NULL;
	global->r_floor = -1;
	global->g_floor = -1;
	global->b_floor = -1;
	global->r_ceiling = -1;
	global->g_ceiling = -1;
	global->b_ceiling = -1;
	global->time = 0;
	global->oldtime = 0;
	if (!extract_file(global, map))
		return (0);
	return (1);
}
