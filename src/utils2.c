/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:36:36 by noah              #+#    #+#             */
/*   Updated: 2024/10/09 14:21:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	strcpy_n(char *dest, char *src, size_t n)
{
	int	i;
	int	len;

	len = (int)ft_strlen(src) - 1;
	if (len < 0)
		len = 0;
	i = 0;
	while (i < (int)n - 1)
	{
		if (i > len)
			dest[i] = ' ';
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

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
	char	*tmp;
	int		i;

	i = 0;
	cur = global->file;
	while (i++ < 6)
		cur = cur->next;
	tmp = ft_strtrim(cur->line, " \t\n");
	while (!tmp[0])
	{
		free(tmp);
		cur = cur->next;
		tmp = ft_strtrim(cur->line, " \t\n");
	}
	free(tmp);
	return (cur);
}

static void	no_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
}

char	*ft_strndup(char *str, size_t len)
{
	char	*result;

	if (!str)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	no_nl(str);
	strcpy_n(result, str, len + 1);
	return (result);
}
