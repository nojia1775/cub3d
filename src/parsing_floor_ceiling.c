/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:49:50 by noah              #+#    #+#             */
/*   Updated: 2024/10/09 15:16:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	atoi_comma(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (str[0] == ',')
		return (-1);
	while (str[i] && str[i] != ',')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

static void	extract_rgb(t_global *global)
{
	int	i;

	i = 0;
	global->r_ceiling = atoi_comma(global->ceiling);
	while (global->ceiling[i] != ',')
		i++;
	global->g_ceiling = atoi_comma(&global->ceiling[++i]);
	while (global->ceiling[i] != ',')
		i++;
	global->b_ceiling = atoi_comma(&global->ceiling[++i]);
	i = 0;
	global->r_floor = atoi_comma(global->floor);
	while (global->floor[i] != ',')
		i++;
	global->g_floor = atoi_comma(&global->floor[++i]);
	while (global->floor[i] != ',')
		i++;
	global->b_floor = atoi_comma(&global->floor[++i]);
}

static int	valid_char(char *str)
{
	int	i;
	int	comma;

	comma = 0;
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (0);
	i = 0;
	while (str[i])
		if (str[i++] == ',')
			comma++;
	if (comma != 2 || ft_strlen(str) < 5 || ft_strlen(str) > 11)
		return (0);
	return (1);
}

int	parsing_floor_ceiling(t_global *global)
{
	if (global->ceiling == NULL || global->floor == NULL)
		return (0);
	if (!valid_char(global->ceiling) || !valid_char(global->floor))
		return (0);
	extract_rgb(global);
	if (global->r_floor < 0 || global->r_floor > 255)
		return (0);
	if (global->g_floor < 0 || global->g_floor > 255)
		return (0);
	if (global->b_floor < 0 || global->b_floor > 255)
		return (0);
	if (global->r_ceiling < 0 || global->r_ceiling > 255)
		return (0);
	if (global->g_ceiling < 0 || global->g_ceiling > 255)
		return (0);
	if (global->b_ceiling < 0 || global->b_ceiling > 255)
		return (0);
	return (1);	
}
