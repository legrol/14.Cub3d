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