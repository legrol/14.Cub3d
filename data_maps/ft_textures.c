/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:10:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/19 21:30:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/***
 * 
 * 
 * 
 * 
 */

static int	ft_get_walls_data(t_cub3d *cub, int *flag, int *fd)
{




}

int	ft_get_textures_data(t_cub3d *cub, int *flag, int *fd)
{
	if (*fd < 0)
	{
		ft_manage_err(OPEN_MAP_ERR);
		*flag = 1;
		return (*flag);
	}
	if (ft_get_walls_data(cub, flag, fd))
	{
		*flag = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
