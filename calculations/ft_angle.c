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

/**
 * The function "ft_angle" sets the initial player angle based on the cardinal 
 * direction they are facing.
 * 
 * @param t_cub3d *cub		Pointer to the main game structure containing 
 * 							player data.
 * @param char cardinal		Character representing the player's initial 
 * 							direction (N, S, E, W).
 * 
 * @return void				Updates the player's angle in degrees.
 * 
 */

void	ft_angle(t_cub3d *cub, char cardinal)
{
	if (cardinal == 'N')
		cub->player.angle = 90;
	if (cardinal == 'S')
		cub->player.angle = 270;
	if (cardinal == 'E')
		cub->player.angle = 0;
	if (cardinal == 'W')
		cub->player.angle = 180;
}
