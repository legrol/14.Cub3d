/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 18:09:41 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 18:09:41 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_angle(t_cub3d *cub, char cardinal)
{
	if (cardinal == NORTH)
		cub->player.angle = 270;
	if (cardinal == SOUTH)
		cub->player.angle = 90;
	if (cardinal == WEST)
		cub->player.angle = 180;
	if (cardinal == EAST)
		cub->player.angle = 0;
}