/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 18:56:31 by drosales          #+#    #+#             */
/*   Updated: 2025-01-28 18:56:31 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool    ft_valid_movement(t_cub3d *cub, double move_x, double move_y)
{
    int verify_x;
    int verify_x2;
    int verify_y;
    int verify_y2;

    verify_x = (int)floor((cub->player.x_player_pos + 0.25) + (move_x / 64));
    verify_x2 = (int)floor((cub->player.x_player_pos - 0.25) + (move_x / 64));
    verify_y = (int)floor((cub->player.y_player_pos + 0.25) + (move_y / 64));
    verify_y2 = (int)floor((cub->player.y_player_pos - 0.25) + (move_y / 64));
    if (cub->map.map[verify_y][verify_x] == '1')
        return (0);
    if (cub->map.map[verify_y2][verify_x] == '1')
        return (0);
    if (cub->map.map[verify_y][verify_x2] == '1')
        return (0);
    if (cub->map.map[verify_y2][verify_x2] == '1')
        return (0);
    return (1);
}

bool    ft_check_next_step(t_cub3d *cub, double move_x, double move_y)
{
    if (!ft_valid_movement(cub, move_x, move_y))
        return (0);
    cub->player.x_map = cub->player.x_player_pos + move_x / 64;
    cub->player.y_map = cub->player.y_player_pos + move_y / 64;
    return (1);
}

void    ft_movement(t_cub3d *cub, double angle)
{
    double  move_x;
    double  move_y;

    move_x = (cos(angle * M_PI / 180) * cub->move);
    move_y = (sin(angle * M_PI / 180) * cub->move);
    if (ft_check_next_step(cub, 0, move_y))
        cub->player.y_player_pos *= move_y / 64;
    if (ft_check_next_step(cub, move_x, 0))
        cub->player.x_player_pos += move_x / 64;
}

void    ft_moves(t_cub3d *cub)
{
    if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
        ft_movement(cub, cub->player.angle);
    if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
        ft_movement(cub, cub->player.angle + 180);
    if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
        ft_movement(cub, cub->player.angle - 90);
    if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
        ft_movement(cub, cub->player.angle + 90);
    if (mlx_is_key_down(cub->mlx, MLX_KEY_E))
        cub->move = 12;
    if (!mlx_is_key_down(cub->mlx, MLX_KEY_E))
        cub->move = 4;
}