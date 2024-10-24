/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:23:28 by nadjemia          #+#    #+#             */
/*   Updated: 2024/10/24 17:00:21 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	close_win(t_global *global)
{
	free_all(global);
	exit(0);
	return (1);
}

static int	escape(int keycode, t_global *global)
{
	if (keycode == 65307)
		close_win(global);
	return (1);
}

void	init_game(t_global *global, char *title)
{
	my_mlx_init(global);
	my_mlx_new_win(global, title);
	mlx_key_hook(global->win, escape, global);
	mlx_hook(global->win, 17, 0, close_win, global);
	mlx_loop(global->mlx);
}