/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:22:40 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 18:44:19 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	add_north(t_global *global, char *str)
{
	char	*tmp;
	
	if (global->north)
		return (0);
	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	global->north = ft_strtrim(tmp, " ");
	if (!global->north)
		return (0);
	return (1);
}

int	add_south(t_global *global, char *str)
{
	char	*tmp;
	
	if (global->south)
		return (0);
	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	global->south = ft_strtrim(tmp, " ");
	if (!global->south)
		return (0);
	return (1);
}

int	add_east(t_global *global, char *str)
{
	char	*tmp;
	
	if (global->east)
		return (0);
	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	global->east = ft_strtrim(tmp, " ");
	if (!global->east)
		return (0);
	return (1);
}

int	add_west(t_global *global, char *str)
{
	char	*tmp;
	
	if (global->west)
		return (0);
	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	global->west = ft_strtrim(tmp, " ");
	if (!global->west)
		return (0);
	return (1);
}

int	add_floor_ceiling(t_global *global, char *str, int f_or_c)
{
	char	*tmp;

	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	if (f_or_c == 1)
	{
		if (global->floor)
			return (0);
		global->floor = ft_strtrim(tmp, " ");
		if (!global->floor)
			return (0);
	}
	else if (f_or_c == 2)
	{
		if (global->floor)
			return (0);
		global->floor = ft_strtrim(tmp, " ");
		if (!global->floor)
			return (0);
	}
	return (1);
}
