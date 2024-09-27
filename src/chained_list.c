/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 23:43:26 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 00:17:02 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_list(t_cub *list)
{
	t_cub	*cur;
	t_cub	*rm;

	if (!list)
		return ;
	cur = list;
	while (cur)
	{
		rm = cur;
		cur = cur->next;
		free(rm->line);
		free(rm);
	}
}

static t_cub	*new_content(char *content)
{
	t_cub	*new;

	new = (t_cub *)malloc(sizeof(t_cub));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->line = ft_strdup(content);
	if (!new->line)
		return (free(new), NULL);
	return (new);
}

int	add_list(t_cub **list, char *content)
{
	t_cub	*cur;

	if (!(*list))
	{
		*list = new_content(content);
		if (!(*list))
			return (0);
		(*list)->prev = NULL;
		return (1);
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_content(content);
	if (!cur->next)
		return(0);
	cur->next->prev = cur;
	return (1);
}