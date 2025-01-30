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

/**
 * The function "ft_rendering" fills the screen background by rendering 
 * the sky and floor colors.
 * 
 * It iterates through each pixel in the window, setting the top half to 
 * the sky color and the bottom half to the floor color.
 * 
 * @param t_cub3d *cub		Pointer to the game structure containing textures 
 * 							and rendering data.
 * 
 * @return int				Returns EXIT_SUCCESS after rendering is complete.
 * 
 */

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
				mlx_put_pixel(cub->background, w, h++, \
				cub->textures.sky_color);
			else
				mlx_put_pixel(cub->background, w, h++, \
				cub->textures.floor_color);
		}
		w++;
	}
	return (printf(MLX_SUCCESS), EXIT_SUCCESS);
}

double	ft_wallsize(t_ray *ray)
{
	double	size;

	if (ray->ray_hypoteneuse_dist < ray->vertical_ray_travel)
		size = (WIDTH / ray->ray_hypoteneuse_dist);
	else
		size = (WIDTH / ray->vertical_ray_travel);
	return (size);
}

void	ft_painting_col(t_cub3d *cub, t_ray *ray, int c)
{
	double		size;
	uint32_t	colors;
	int			i;
	int 		first_pixel;
	int			pixels;

	i = 0;
	pixels = 0;
	size = ft_wallsize(ray);
	if (first_pixel < 0)
	{
		pixels = -first_pixel;
		first_pixel = 0;
	}
	while (i < HEIGHT)
	{
		if (i > first_pixel && i < HEIGHT - 1)
		{
			colors = ft_walls_colors(cub, ray, \
					(i - first_pixel + pixels) / size);
			mlx_put_pixel(cub->walls, c, i, colors);	
		}
		i++;
	}
}

uint32_t	ft_rgba(uint8_t pixel[4])
{
	uint32_t	p;

	p = 0;
	p |= ((uint32_t)pixel[0] << 24);
	p |= ((uint32_t)pixel[1] << 16);
	p |= ((uint32_t)pixel[2] << 8);
	p |= pixel[3];
	return (p);
}

uint32_t	ft_get_the_colors(double x, double size, mlx_texture_t *texture)
{
	uint8_t			rgba[4];
	uint32_t		indx;
	unsigned int	i;

	i = 0;
	if (!texture || !texture->pixels || x >= 1 || size >= 1)
		return (0);
	indx = ((uint32_t)(texture->height * size) * texture->width \
			+ (uint32_t)(texture->width * x)) * texture->bytes_per_pixel;
	while (i < 4)
	{
		rgba[i] = texture->pixels[indx + i];
		i++;
	}
	return (ft_rgba(rgba));
}