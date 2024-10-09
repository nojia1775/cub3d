/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:48:20 by noah              #+#    #+#             */
/*   Updated: 2024/10/09 11:44:33 by codespace        ###   ########.fr       */
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
	int		r_floor;
	int		g_floor;
	int		b_floor;
	int		r_ceiling;
	int		g_ceiling;
	int		b_ceiling;
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
int		thereis_charset(char *str, char *set);
int		parsing_floor_ceiling(t_global *global);
int		extract_map(t_global *global);
t_cub	*get_pos_map(t_global *global);
void	free_and_null(void **data);
char	*ft_strndup(char *str, size_t len);
void	strcpy_n(char *dest, char *src, size_t n);
int		parsing_map(t_global *global);
int		empty_line(char *str);
void	degat_des_eaux(char **map);
int		map_closed(char **map);

#endif