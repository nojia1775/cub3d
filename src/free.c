/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:13:13 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 00:14:58 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_all(t_global *global)
{
	if (global->south)
		free(global->south);
	if (global->north)
		free(global->north);
	if (global->east)
		free(global->east);
	if (global->west)
		free(global->west);
	if (global->file)
		free_list(global->file);
}