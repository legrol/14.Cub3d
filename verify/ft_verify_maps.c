/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:12:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 20:19:28 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_verify_map" validates the entire map structure within the 
 * `t_cub3d` input. It checks for the existence of the map, validates its 
 * boundary lines (first and last), and ensures that all characters in the 
 * map are valid.
 * 
 * @param t_cub3d *input			A pointer to the main structure containing 
 * 									map details and metadata.
 * 
 * @return int						Returns EXIT_SUCCESS if the map is valid. 
 * 									Returns EXIT_FAILURE if any validation 
 * 									fails.
 * 
 */

int	ft_verify_map(t_cub3d *input)
{
	int	warning;

	warning = 0;
	if (!input || !input->map.map)
		return (EXIT_FAILURE);
	if (ft_verify_extremes(input, input->map.map) || \
	ft_verify_core(input->map.map) || ft_verify_closure(input) || \
	ft_verify_spaces(input->map.map))
		warning = 1;
	if (warning == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
