/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:10:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/25 19:30:46 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * The function "ft_get_textures_data" initializes the process of retrieving 
 * texture data from a file. It validates the file descriptor and delegates 
 * the task of processing wall texture data to "ft_get_walls_data".
 * 
 * @param t_cub3d *cub			A pointer to the main game structure containing 
 * 								texture and map information.
 * @param int *flag				A pointer to a flag that indicates whether 
 * 								an error occurred.
 * @param int *fd				A pointer to the file descriptor of the map 
 * 								file.
 * 
 * @return int					Returns EXIT_SUCCESS if all texture data is 
 * 								successfully processed. Returns EXIT_FAILURE 
 * 								if an error occurs.
 * 
 * The function "ft_get_walls_data" reads texture data for the walls of the 
 * cube (e.g., "N", "S", "E", "W") from a file. It processes a fixed number 
 * of sides (`SIDES_CUBE`), validates each texture, and adjusts the file 
 * descriptor as needed. Finally, it verifies that all required identifiers 
 * are present.
 * 
 * @param t_cub3d *cub			A pointer to the main game structure 
 * 								containing texture and map information.
 * @param int *flag				A pointer to a flag that indicates whether 
 * 								an error occurred.
 * @param int *fd				A pointer to the file descriptor of the map 
 * 								file.
 * 
 * @return int					Returns EXIT_SUCCESS if all texture data is 
 * 								successfully processed. Returns EXIT_FAILURE 
 * 								if an error occurs.
 * 
 */

static int	ft_get_walls_data(t_cub3d *cub, int *flag, int *fd)
{
	char	**cell;
	int		i;
	int		j;

	cell = NULL;
	i = 0;
	j = 0;
	while (i < SIDES_CUBE)
	{
		if (ft_split_line(&cell, *fd))
			return (EXIT_FAILURE);
		j++;
		if (ft_verify_texture(cub, cell, &i, j))
			*fd = 1;
	}
	ft_verify_ids(cub, fd, i);
	return (EXIT_SUCCESS);
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
