/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:13:13 by noah              #+#    #+#             */
/*   Updated: 2024/10/07 13:27:50 by codespace        ###   ########.fr       */
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
}