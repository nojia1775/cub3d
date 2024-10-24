/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:59:24 by noah              #+#    #+#             */
/*   Updated: 2024/10/24 15:38:54 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static	int	is_element(t_global *global, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (add_north(global, str + 3));
	else if (!ft_strncmp(str, "SO ", 3))
		return (add_south(global, str + 3));
	else if (!ft_strncmp(str, "EA ", 3))
		return (add_east(global, str + 3));
	else if (!ft_strncmp(str, "WE ", 3))
		return (add_west(global, str + 3));
	else if (!ft_strncmp(str, "F ", 2))
		return (add_floor_ceiling(global, str + 2, 1));
	else if (!ft_strncmp(str, "C ", 2))
		return (add_floor_ceiling(global, str + 2, 2));
	return (0);
}

static int	valid_file(t_global *global, t_cub *list)
{
	t_cub	*cur;
	int		count;

	count = 1;
	cur = list;
	while (cur)
	{
		if (count < 7 && !is_element(global, cur->line))
			return (0);
		cur = cur->next;
		count++;
	}
	if (!parsing_floor_ceiling(global))
		return (0);
	return (1);
}

int	parsing(t_global *global)
{
	if (!valid_file(global, global->file))
		return (0);
	if (!extract_map(global))
		return (0);
	if (!parsing_map(global))
		return (0);
	return (1);
}