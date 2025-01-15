/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verf_1l_ll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-15 18:02:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2025-01-15 18:02:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/****
 * 
 * 
 * 
 * 
 */

static int	ft_verify_last_line()
{

	
}

static int	ft_verify_first_line()
{

	
}

int	ft_verify_extremes(t_cub3d *details, char **map)
{
	int	flag;

	flag = 0;
	if (ft_verify_first_line())
		flag = 1;
	if (ft_verify_last_line())
		flag = 1;
	if (flag == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
