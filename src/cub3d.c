/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 16:24:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2025-01-14 16:24:06 by rdel-olm         ###   ########.fr       */
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

	ft_control_args(argc, argv);
	cub = ft_init(argv[1]); // pdte desarrollar
	map = ft_init_map(argv[1]); // pdte desarrollar


	return (EXIT_SUCCESS);
}
