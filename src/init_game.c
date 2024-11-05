/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:23:28 by nadjemia          #+#    #+#             */
/*   Updated: 2024/11/05 15:43:43 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	close_win(t_global *global)
{
	free_all(global);
	exit(0);
	return (1);
}

static int	keys(int keycode, t_global *global)
{
	if (keycode == ESC)
		close_win(global);
	if (keycode == UP)
		global->player->y -= SPEED;
	if (keycode == DOWN)
		global->player->y += SPEED;
	if (keycode == LEFT)
		global->player->x -= SPEED;
	if (keycode == RIGHT)
		global->player->x += SPEED;
	printf("%f %f\n", global->player->x, global->player->y);
	return (1);
}

void	init_game(t_global *global, char *title)
{
	t_player	player;

	get_player_coor(&player.x, &player.y, global);
	global->player = &player;
	my_mlx_init(global);
	my_mlx_new_win(global, title);
	display(global);
	mlx_hook(global->win, 17, 0, close_win, global);
	mlx_hook(global->win, 2, 1L<<0, keys, global);
	mlx_loop(global->mlx);
}
