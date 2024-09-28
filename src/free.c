/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:13:13 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 18:54:35 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_no_null(void *data)
{
	if (data)
		free(data);
}

void	free_all(t_global *global)
{
	free_no_null((void *)global->south);
	free_no_null((void *)global->north);
	free_no_null((void *)global->east);
	free_no_null((void *)global->west);
	free_no_null((void *)global->ceiling);
	free_no_null((void *)global->floor);
	if (global->file)
		free_list(global->file);
}