/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:25:13 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 00:44:04 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	extract_file(t_global *global, char *map)
{
	int		fd;
	char	*str;
	
	str = "";
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		add_list(&global->file, str);
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
	if (!extract_file(global, map))
		return (0);
	return (1);
}