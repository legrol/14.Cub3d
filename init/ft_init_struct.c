/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 18:16:06 by drosales          #+#    #+#             */
/*   Updated: 2025-01-16 18:16:06 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_init_coord_flags(t_cub3d *structure)
{
    structure->textures.sky_flag = 0;
    structure->textures.floor_flag = 0;
    structure->textures.north_flag = 0;
    structure->textures.south_flag = 0;
    structure->textures.west_flag = 0;
    structure->textures.east_flag = 0;
}

void    ft_init_player(t_cub3d *structure)
{
    structure->player.x_map = 0;
    structure->player.y_map = 0;
    structure->player.x_player_pos = 0;
    structure->player.y_player_pos = 0;
    structure->player.angle = 0;
}

void    ft_init_textures(t_cub3d *structure)
{
    ft_init_coord_flags(structure);
    structure->textures.north_text = NULL;
    structure->textures.south_text = NULL;
    structure->textures.west_text = NULL;
    structure->textures.east_text = NULL;
    structure->textures.north_path = NULL;
    structure->textures.south_path = NULL;
    structure->textures.west_path = NULL;
    structure->textures.east_path = NULL;
    structure->textures.sky_color = 0;
    structure->textures.floor_color = 0;
}

int ft_setup(t_cub3d *structure)
{
    ft_init_textures(structure);
    ft_init_player(structure);
    structure->mlx = NULL;
    structure->file = NULL;
    structure->map.map = NULL;
    structure->map.line_map = 0;
    structure->map.x_map = 0;
    structure->map.y_map = 0;
    structure->background = NULL;
    structure->walls = NULL;
    structure->move = 0;
    structure->ray_number = 0;
    return (SUCCESS);
}

void    ft_init_walls(t_cub3d *structure, mlx_image_t **image)
{
    *image = mlx_new_image(structure->mlx, WIDTH, HEIGHT);
    if (!*image)
    {
        printf(FLOOR_OR_SKY_ERR);
        exit (FAILURE);
    }
    if (mlx_image_to_window(structure->mlx, *image, 0, 0) == -1)
    {
        printf(IMG_TO_WINDOW_ERR);
        exit (FAILURE);
    }
}