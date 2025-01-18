/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:35:15 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/18 19:46:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ============================================================================
// Libraries
// ============================================================================

# include <unistd.h>		// for write...
# include <stdlib.h>		// for typedef, malloc...
# include <math.h>			// for PI, etc.
# include <fcntl.h>			// for open, O_RDONLY, etc.
# include <stdio.h>			// for printf...
# include <string.h>		// for strdup, strlen, etc.
# include <errno.h>			// for use errno, perror ...

// ============================================================================
// Access to my libraries
// ============================================================================

# include "colors.h"
# include "examft.h"
# include "ft_macros.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "get_next_line.h"
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// ============================================================================
// Structures
// ============================================================================

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*background;
	mlx_image_t		*walls;
	t_map			map;
	t_player		player;
	t_textures		textures;
	char			*file;
	int				ray_number;
	int				move;
}					t_cub3d;

typedef struct s_map
{
	int			x_map;
	int			y_map;
	int			line_map;
	char		**map;
}				t_map;

typedef struct s_line
{
	int			x;
	int			y;
	int			y0;
	int			y1;
	int			x_text;
	int			y_text;
}				t_line;

typedef struct s_paint_coord
{
	int			x;
	int			y;
}				t_paint_coord;

typedef struct s_player
{
	double		angle;
	double		x_player_pos;
	double		y_player_pos;
	int			x_map;
	int			y_map;
	t_ray		ray[WIDTH];
}				t_player;

typedef struct s_ray
{
	int			flag; // Flag used when the ray touches the wall;
	int			x_map;
	int			y_map;
	double		angle;
	double		angle_ret;
	double		x_player_pos;
	double		y_player_pos;
	double		ray_x;
	double		ray_y;
	double		ray_dist_to_x;
	double		ray_dist_to_y;
	double		cell_crossing_dist_x;
	double		cell_crossing_dist_y;
	double		current_side_dist_x;
	double		current_side_dist_y;
	double		wall_ray_hit_dist;
	double		wall_visible_height;
	double		ray_hit_in_map_dist;
	double		ray_hypoteneuse_dist;
	double		vertical_ray_travel;
	double		ray_move_x;
	double		ray_move_y;
}				t_ray;

typedef struct s_textures
{
	mlx_texture_t	*north_text;
	mlx_texture_t	*south_text;
	mlx_texture_t	*west_text;
	mlx_texture_t	*east_text;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	unsigned int	sky_color;
	unsigned int	floor_color;
	int				north_flag;
	int				south_flag;
	int				west_flag;
	int				east_flag;
	int				sky_flag;
	int				floor_flag;
}					t_textures;

// ============================================================================
// Control functions
// ============================================================================

int		ft_control_args(int argc, char **argv);
int		ft_ext_valid(char *map_name);

// ============================================================================
// Verify functions
// ============================================================================

int		ft_number_players(char **map);
int		ft_verify_closure(t_cub3d *details);
int		ft_verify_core(char **map);
int		ft_verify_extremes(t_cub3d *details, char **map);
int		ft_verify_map(t_cub3d *input);
int		ft_verify_spaces(char **map);

// ============================================================================
// Management errors
// ============================================================================

void	ft_forbidden_space(int line, int col);
void	ft_invalid_char(char **map, int line, int pos);
void	ft_invalid_side(int line, int warning);
void	ft_manage_err(const char *err);
void	ft_players(int index);

// ============================================================================
// Functions to release
// ============================================================================

// ============================================================================
// Initialization functions
// ============================================================================

void	ft_init_coord_flags(t_cub3d *structure);
void	ft_init_player(t_cub3d *structure);
void	ft_init_textures(t_cub3d *structure);
int		ft_setup(t_cub3d *structure);
void	ft_init_walls(t_cub3d *structure, mlx_image_t **image);

// ============================================================================
// Utils functions
// ============================================================================

int		ft_count_col(char **str);

#endif