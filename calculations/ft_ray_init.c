/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 18:20:28 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 18:20:28 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_ray_init(t_cub3d *cub)
{
	int		i;
	double	angle;
	double	fov;

	fov = FOV * M_PI / 180;
	angle = cub->player.angle * M_PI / 180;
	i = 0;
	while (i < WIDTH)
	{
		cub->player.ray[i].angle = angle - (fov / 2) \
			+ ((fov / WIDTH) * i);
		cub->player.ray[i].angle_ret = cub->player.ray[i].angle;
		if (cub->player.ray[i].angle < 0)
			cub->player.ray[i].angle += 2 * M_PI;
		i++;
	}
}

void	ft_init_ray_values(t_cub3d *cub, t_ray *ray)
{
	ray->ray_move_x = 0;
	ray->ray_move_y = 0;
	ray->x_map = cub->player.x_map;
	ray->y_map = cub->player.y_map;
	ray->x_player_pos = cub->player.x_player_pos;
	ray->y_player_pos = cub->player.y_player_pos;
	ray->ray_x = cos(ray->angle);
	ray->ray_y = sin(ray->angle);
	ray->ray_dist_to_x = 1 / fabs(ray->ray_x);
	ray->ray_dist_to_y = 1 / fabs(ray->ray_y);
	if (ray->ray_x < 0)
		ray->ray_move_x = -1;
	else
		ray->ray_move_x = 1;
	if (ray->ray_y < 0)
		ray->ray_move_y = -1;
	else
		ray->ray_move_y = 1;
	ray->flag = 0;
}