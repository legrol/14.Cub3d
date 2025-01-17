/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:24:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/17 12:51:07 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/***
 * 
 * 
 * 
 * 
 */

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	t_map	*map;

	if (ft_control_args(argc, argv))
		return (EXIT_FAILURE);
	cub = ft_init(argv[1]); // pdte desarrollar
	map = ft_init_map(argv[1]); // pdte desarrollar


	return (EXIT_SUCCESS);
}
