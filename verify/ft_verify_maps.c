/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 18:12:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2025-01-15 18:12:45 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * 
 * 
 * 
 */

int	ft_verify_map(t_cub3d *input)
{
	int	warning;

	warning = 0;
	if (!input || !input->map->map)
		return (EXIT_FAILURE);
	if (ft_verify_extremes(input, input->map->map))
		warning = 1;
	if (warning == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
