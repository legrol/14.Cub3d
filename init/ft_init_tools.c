/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 17:50:17 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 17:50:17 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_player_position(t_cub3d *cub, char **map)
{
	int		x;
	int		y;
	char	cell;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == NORTH || map[x][y] == SOUTH \
				|| map[x][y] == WEST || map[x][y] == EAST)
			{
				cell = map[x][y];
				cub->player.x_player_pos = y + 0.5;
				cub->player.y_player_pos = x + 0.5;
				cub->player.x_map = y;
				cub->player.y_map = x;
			}
			y++;
		}
		x++;
	}
	ft_angle(cub, cell);
	ft_ray_init(cub);
}