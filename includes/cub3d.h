/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:35:15 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/15 19:36:36 by drosales         ###   ########.fr       */
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
// Several controls
// ============================================================================

int		ft_control_args(int32_t argc, char **argv);
int		ft_ext_valid(char *map_name);

// ============================================================================
// Drawing functions
// ============================================================================


// ============================================================================
// Management errors
// ============================================================================


// ============================================================================
// Functions to release
// ============================================================================


// ============================================================================
// Initialization functions
// ============================================================================


// ============================================================================
// Peripherals
// ============================================================================


// ============================================================================
// Several functions
// ============================================================================


#endif