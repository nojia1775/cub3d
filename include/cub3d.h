/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:48:20 by noah              #+#    #+#             */
/*   Updated: 2024/10/24 17:25:18 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WIDTH 889
# define HEIGHT 500

/*
droite = 65363 ou 100
gauche = 65361 ou 97
haut = 65362 ou 119
bas = 65364 ou 115
*/

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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	vector_x;
	double	vector_y;
	double	plane_x;
	double	plane_y;
};

typedef struct s_global
{
	void	*mlx;
	void	*win;
	void	*img;
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

typedef struct s_vars
{
	t_cub	*cur;
	int		begin;
	int		end;
	int		lines;
	int		i;
	char	**map;
}	t_vars;

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
void	my_mlx_init(t_global *global);
void	my_mlx_new_win(t_global *global, char *title);
void	init_game(t_global *global, char *title);

#endif