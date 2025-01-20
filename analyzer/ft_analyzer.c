/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:24:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/19 01:22:20 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_mapping(t_cub3d *cub, int fd)
{
	char	*lines;
	char	*map;

	lines = NULL;
	map = NULL;
	lines = get_next_line(fd);
	if (!lines)
		return (ft_manage_err(READ_ERR), EXIT_FAILURE);
	map = ft_matrix_to_str(lines, fd);
	if (!map)
		return (ft_manage_err(MATRIX_TO_STR_ERR), EXIT_FAILURE);
	map = ft_strtrim(map, "\n");
	if (!map)
		return (ft_manage_err(FT_STRTRIM_ERR), EXIT_FAILURE);
	if (ft_map_spliting(cub, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_analyzer(char *argv, t_cub3d *cub)
{
	int	fd;
	int	warning;

	warning = 0;
	// if (xxxxx)
	// 	return (EXIT_FAILURE);
	cub->file = argv;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_manage_err(OPEN_ERR), EXIT_FAILURE);
	if (ft_get_textures_data(cub, &warning, &fd) || ft_mapping())
		warning = 1;
	close(fd);
	//get size map
	return (warning);
}

