/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 17:16:27 by drosales          #+#    #+#             */
/*   Updated: 2025-01-29 17:16:27 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_angles_checker(double *angle, double i)
{
    *angle += i;
    if (*angle >= 360)
        *angle -= 360;
    if (*angle < 0)
        *angle += 360; 
}

void    ft_rotation(t_cub3d *cub)
{
    if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
        ft_angles_checker(&cub->player.angle, -3);
    if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
        ft_angles_checker(&cub->player.angle, 3);
}

void    ft_vertical_impact(t_ray *ray)
{
    if (ray->ray_x > 0 && ray->ray_y >= 0)
		ray->wall_visible_height = (ray->ray_hit_in_map_dist - ray->y_map) * 1920;
	else if (ray->ray_x <= 0 && ray->ray_y > 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->y_map) * 1920;
	else if (ray->ray_x >= 0 && ray->ray_y < 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->y_map) * 1920;
	else if (ray->ray_x < 0 && ray->ray_y <= 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->y_map) * 1920;
}

void    ft_horizontal_impact(t_ray *ray)
{
    if (ray->ray_x > 0 && ray->ray_y >= 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->x_map) * 1920;
	else if (ray->ray_x <= 0 && ray->ray_y > 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->x_map) * 1920;
	else if (ray->ray_x >= 0 && ray->ray_y < 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->x_map) * 1920;
	else if (ray->ray_x < 0 && ray->ray_y <= 0)
		ray->wall_ray_hit_dist = (ray->ray_hit_in_map_dist - ray->x_map) * 1920;
}