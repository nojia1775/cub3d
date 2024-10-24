/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:19:31 by nadjemia          #+#    #+#             */
/*   Updated: 2024/10/24 12:22:38 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_init(t_global *global)
{
	global->mlx = mlx_init();
	if (!global->mlx)
	{
		free_all(global);
		exit(4);
	}
}

void	my_mlx_new_win(t_global *global, char *title)
{
	global->win = mlx_new_window(global->mlx, WIDTH, HEIGHT, title);
	if (!global->win)
	{
		free_all(global);
		exit(5);
	}
}
