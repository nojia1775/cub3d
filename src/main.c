/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:50:27 by noah              #+#    #+#             */
/*   Updated: 2024/10/24 17:10:54 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	name_map(char *map_name)
{
	int	i;

	i = 0;
	if (ft_strlen(map_name) < 5)
		return (0);
	while (map_name[i])
		i++;
	i -= 4;
	if (ft_strncmp(&map_name[i], ".cub", 4))
		return (0);
	return (1);
}

static int	valid_arguments(int argc, char **argv, char **env)
{
	if (!env[0])
		return (0);
	if (argc != 2)
		return (0);
	if (!name_map(argv[1]))
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_global	global;

	if (!valid_arguments(argc, argv, env))
		return (printf("Error\n"), 1);
	if (!init_global(&global, argv[1]))
		return (printf("Error\n"), 2);
	if (!parsing(&global))
		return (printf("Error\n"), free_all(&global), 3);
	init_game(&global, "CUB3D");
	free_all(&global);
	return (0);
}
