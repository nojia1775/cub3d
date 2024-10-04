/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:36:36 by noah              #+#    #+#             */
/*   Updated: 2024/10/04 18:06:01 by nadjemia         ###   ########.fr       */
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

char	*ft_strndup(char *str, size_t len)
{
	char	*result;
	
	printf("--- %s\n", str);
	if (!str)
		return (NULL);
	if (len > ft_strlen(str))
		result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (len > ft_strlen(str))
		ft_strlcpy(result, str, ft_strlen(str) + 1);
	else
		ft_strlcpy(result, str, len + 1);
	printf("--- %s\n\n", result);
	return (NULL);
}
