/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:36:36 by noah              #+#    #+#             */
/*   Updated: 2024/09/29 12:58:07 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	thereis_charset(char *str, char *set)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
			if (str[i] == set[j++])
				return (1);
		i++;
	}
	return (0);
}

t_cub	*get_pos_map(t_global *global)
{
	t_cub	*cur;
	int		i;

	i = 0;
	cur = global->file;
	while (i++ < 6)
		cur = cur->next;
	return (cur);
}