/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 18:39:32 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 18:39:32 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_rendering(t_cub3d *cub)
{
	int	w;
	int	h;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			if (h < HEIGHT / 2)
				mlx_put_pixel(cub->background, w, h++, cub->textures.sky_color);
			else
				mlx_put_pixel(cub->background, w, h++, cub->textures.floor_color);
		}
		w++;
	}
	return(printf(MLX_SUCCESS), EXIT_SUCCESS);
}