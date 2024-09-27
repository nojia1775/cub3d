/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:48:20 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 00:31:03 by noah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_cub
{
	char		*line;
	struct s_cub	*next;
	struct s_cub	*prev;
}	t_cub;

typedef struct s_global
{
	char	*south;
	char	*north;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
	char	**map;
	t_cub	*file;
}	t_global;

int		init_global(t_global *global, char *map);
int		add_list(t_cub **list, char *content);
void	free_list(t_cub *list);
void	free_all(t_global *global);

#endif