/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:13:13 by noah              #+#    #+#             */
/*   Updated: 2024/10/25 15:07:43 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_and_null(void **data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_all(t_global *global)
{
	free_and_null((void **)&global->south);
	free_and_null((void **)&global->north);
	free_and_null((void **)&global->east);
	free_and_null((void **)&global->west);
	free_and_null((void **)&global->ceiling);
	free_and_null((void **)&global->floor);
	if (global->file)
		free_list(global->file);
	if (global->map)
		free_map(global->map);
	mlx_destroy_window(global->mlx, global->win);
	mlx_destroy_display(global->mlx);
	free(global->mlx);
}
