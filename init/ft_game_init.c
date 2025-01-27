/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:34 by drosales          #+#    #+#             */
/*   Updated: 2025/01/27 21:10:24 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_playing_mode(t_cub3d *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_DISABLED);
	if (!cub->mlx)
	{
		ft_manage_err(MLX_INIT_ERR);
		return (EXIT_FAILURE);
	}
	ft_init_walls(cub, cub->background);
	ft_init_walls(cub, cub->walls);
	cub->move = 4;
	ft_player_position(); // KEEP CODING
	ft_render();           // KEEP CODING
}

void    ft_game_init(t_cub3d *cub)
{
	ft_playing_mode(cub);
	mlx_loop_hook(cub->mlx, xxxxxx, cub); // FT_CALLBACK NEEDED
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
}

