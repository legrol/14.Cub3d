/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:08 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/26 18:13:21 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_fetch_rgb" determines the appropriate way to parse and
 * encode RGB values based on the input format. It supports two formats:
 * - Hexadecimal RGB strings ("R,G,B")
 * - Separate RGB values in multiple cells.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB data.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns RGB_VALID_MAX (default value) on error.
 * 
 * The function "ft_parse_rgb_hex" parses an RGB string in "R,G,B" format and
 * encodes it into a single unsigned integer (ARGB format). It validates that
 * the input values are within the allowed range (0-255).
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and the RGB string.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns EXIT_FAILURE if any value is invalid.
 * 
 * The function "ft_encode_rgb" encodes RGB values into a single unsigned 
 * integer (ARGB format). It validates that the input values are within the
 * allowed range (0-255) and reports errors for invalid values.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and values as strings.
 * 
 * @return unsigned int         Returns the encoded ARGB color value if valid.
 *                              Returns EXIT_FAILURE if any value is invalid.
 * 
 * The function "ft_handle_rgb_error" handles errors related to invalid RGB
 * color values. It prints an error message that includes the identifier and
 * the specific invalid values for red, green, or blue channels.
 * 
 * @param char **cell           A pointer to an array of strings containing
 *                              the RGB identifier and values.
 * @param int red               The red channel value.
 * @param int green             The green channel value.
 * @param int blue              The blue channel value.
 * 
 * @return void                 No return value. Logs the error message.
 * 
 */

static void	ft_handle_rgb_error(char **cell, int red, int green, int blue)
{
	ft_manage_err(RGB_ERR);
	ft_putstr_fd(cell[0], 2);
	ft_putstr_fd(". ", 2);
	if (red < 0 || red > RGB_VALID_MAX)
	{
		ft_putstr_fd("red = ", 2);
		ft_putnbr_fd(red, 2);
		ft_putstr_fd(". ", 2);
	}
	if (green < 0 || green > RGB_VALID_MAX)
	{
		ft_putstr_fd("green = ", 2);
		ft_putnbr_fd(green, 2);
		ft_putstr_fd(". ", 2);
	}
	if (blue < 0 || blue > RGB_VALID_MAX)
	{
		ft_putstr_fd("blue = ", 2);
		ft_putnbr_fd(blue, 2);
		ft_putstr_fd(".", 2);
	}
	ft_putstr_fd("\n", 2);
}

static unsigned int	ft_encode_rgb(char **cell)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = 0;
	green = 0;
	blue = 0;
	if (!cell || !cell[0] || !cell[1] || !cell[2] || !cell[3])
		return (EXIT_FAILURE);
	red = ft_atoi(cell[1]);
	green = ft_atoi(cell[2]);
	blue = ft_atoi(cell[3]);
	if (red < RGB_VALID_MIN || red > RGB_VALID_MAX || green < RGB_VALID_MIN \
	|| green > RGB_VALID_MAX || blue < RGB_VALID_MIN || blue > RGB_VALID_MAX)
	{
		ft_handle_rgb_error(cell, red, green, blue);
		return (EXIT_FAILURE);
	}
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

static unsigned int	ft_parse_rgb_hex(char **cell)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	char			**rgb;

	red = 0;
	green = 0;
	blue = 0;
	rgb = ft_split(cell[1], ',');
	if (!rgb)
		return (ft_manage_err(SPLIT_ERR), EXIT_FAILURE);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	ft_split_clear(rgb);
	if (red < RGB_VALID_MIN || red > RGB_VALID_MAX || green < RGB_VALID_MIN \
	|| green > RGB_VALID_MAX || blue < RGB_VALID_MIN || blue > RGB_VALID_MAX)
	{
		ft_handle_rgb_error(cell, red, green, blue);
		return (EXIT_FAILURE);
	}
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

unsigned int	ft_fetch_rgb(char **cell)
{
	unsigned int	rgb_color;

	rgb_color = 0;
	if (ft_split_len(cell) == 2)
	{
		rgb_color = ft_parse_rgb_hex(cell);
		if (rgb_color == EXIT_FAILURE)
			return (RGB_VALID_MAX);
	}
	else if (ft_split_len(cell) == 4)
	{
		rgb_color = ft_encode_rgb(cell);
		if (rgb_color == EXIT_FAILURE)
			return (RGB_VALID_MAX);
	}
	return (rgb_color);
}

uint32_t	ft_walls_colors(t_cub3d *cub, t_ray *ray, double size)
{
	uint32_t	c;

	if (ray->flag == 0)
	{
		if (ray->ray_x > 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.east_text);
		if (ray->ray_x < 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.west_text);
		return (c);
	}
	else if (ray->flag == 1)
	{
		if (ray->ray_y > 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.south_text);
		if (ray->ray_y < 0)
			c = ft_get_the_colors(ray->ray_hit_in_map_dist \
				- (int)ray->ray_hit_in_map_dist, size, cub->textures.north_text);
		return (c);
	}
	return (0x33333388);
}
