/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:09:05 by nadjemia          #+#    #+#             */
/*   Updated: 2024/11/05 12:30:41 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_player(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_pixel_put(global->mlx, global->win, global->player->x + j, global->player->y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	display(t_global *global)
{
	draw_player(global);
	return (1);
}