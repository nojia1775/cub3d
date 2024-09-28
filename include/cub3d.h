/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah <noah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:48:20 by noah              #+#    #+#             */
/*   Updated: 2024/09/28 18:53:27 by noah             ###   ########.fr       */
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

typedef enum e_element
{
	NO,
	SO,
	EA,
	WE
}	t_element;

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
int		add_north(t_global *global, char *str);
int		add_south(t_global *global, char *str);
int		add_east(t_global *global, char *str);
int		add_west(t_global *global, char *str);
int		add_floor_ceiling(t_global *global, char *str, int f_or_c);
int		parsing(t_global *global);

#endif