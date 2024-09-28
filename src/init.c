/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:25:13 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 19:23:30 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	extract_file(t_global *global, char *map)
{
	int		fd;
	char	*str;
	char	*tmp;

	str = "";
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = ft_strtrim(str, " \n\t");
		free(str);
		if (tmp[0])
			add_list(&global->file, tmp);
		free(tmp);
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
	if (!extract_file(global, map))
		return (0);
	return (1);
}